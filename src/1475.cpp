#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

#define MAXN 256

std::string result[MAXN];
std::string factorial[MAXN];
std::string matrix[MAXN][MAXN];

void multi(const std::string& x, int y, std::string& z)
{
	size_t i;
	int carry = 0;
	int value = 0;
	for( i = 0; i < x.size(); i++ )
	{
		value = (x[i]-'0')*y + carry;
		carry = value/10;
		value = value%10;
		z.push_back(value+'0');
	}
	while( carry != 0 )
	{
		z.push_back(carry%10+'0');
		carry /= 10;
	}
}
void plus_str(const std::string& x, const std::string& y, std::string& z)
{
	size_t i;
	int value = 0;
	int carry = 0;
	const std::string& a = (x.size() > y.size())?y:x;
	const std::string& b = (x.size() > y.size())?x:y;
	for( i = 0; i < a.size(); i++ )
	{
		value = (a[i]-'0')+(b[i]-'0')+carry;
		carry  = value/10;
		value = value%10;
		z.push_back(value+'0');
	}
	while( i < b.size() )
	{
		value = carry+(b[i]-'0');
		carry = value/10;
		value = value%10;
		z.push_back(value+'0');
		i += 1;
	}
	while( carry != 0 )
	{
		z.push_back(carry%10+'0');
		carry /= 10;
	}
}
void factor(int n)
{
	int i;
	factorial[0] = "1";
	factorial[1] = "1";
	for( i = 2; i <= n; i++ )
		multi(factorial[i-1],i,factorial[i]);
}

void recursive(int n, int m)
{
	std::string x,y;
	if( n == m )
	{
		matrix[n][m] = factorial[n];
		return;
	}
	if( m == 1 )
	{
		matrix[n][m] = "1";
		return;
	}
	if( matrix[n-1][m] == "" )
		recursive(n-1,m);
	if( matrix[n-1][m-1] == "" )
		recursive(n-1,m-1);
	multi(matrix[n-1][m],m,x);
	multi(matrix[n-1][m-1],m,y);
	plus_str(x,y,matrix[n][m]);
}
void compute(int n)
{
	int i,j;
	std::string tmp;
	factor(n);
	for( i = 1; i <= n; i++ )
	{
		for( j = 1; j <= i; j++ )
		{
			if( matrix[i][j] == "" )
				recursive(i,j);
			plus_str(matrix[i][j],result[i],tmp);
			result[i] = tmp;
			tmp.clear();
		}
		std::reverse(result[i].begin(),result[i].end());
	}
}
int main()
{
	int n;
	compute(200);
	while( (std::cin >> n) && n > 0 )
		std::cout << result[n] << std::endl;
	return 0;
}

