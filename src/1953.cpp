#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#define MAXN 128

char x[MAXN];
char y[MAXN];

size_t table[MAXN][MAXN];
int back[MAXN][MAXN];

void dp(char* x, int m, char* y, int n)
{
	int i,j,a,b;
	for( i = 0; i <= m; i++ )
	{
		table[i][0] = i;
		if( i > 0)
			back[i][0] = (i-1)*MAXN;
	}
	for( i = 0; i <= n; i++ )
	{
		table[0][i] = i;
		if( i > 0 )
			back[0][i] = i-1;
	}
	for( i = 1; i <= m; i++ )
		for( j = 1; j <= n; j++ )
		{
			if(x[i-1] == y[j-1]) 
			{
				if(table[i][j] > table[i-1][j-1]+1)
				{

					table[i][j] = table[i-1][j-1]+1;
					back[i][j] = (i-1)*MAXN+j-1;
				}
			}
			else
			{
				a = table[i-1][j]+1;
				b = table[i][j-1]+1;
				if( table[i][j] > a || table[i][j] > b)
				{

					if( a < b )
					{
						table[i][j] = a;
						back[i][j] = (i-1)*MAXN+j;
					}
					else
					{
						table[i][j] = b;
						back[i][j] = i*MAXN+j-1;
					}

				}
			}
		}

}
void fruits(char* x, char*y)
{
	int a,b;
	std::string result;
	int m = strlen(x);
	int n = strlen(y);
	memset(table,1,sizeof(table));
	memset(back,-1,sizeof(back));
	dp(x,m,y,n);
	while( back[m][n] >= 0 )	
	{
		a = back[m][n]/MAXN;
		b = back[m][n]%MAXN;
		if( a == m )
			result.push_back(y[b]);	
		else if( b == m )
			result.push_back(x[a]);
		else
			result.push_back(x[a]);
		m = a;
		n = b;
	}
	//result.reverse();
	std::reverse(result.begin(),result.end());
	printf("%s\n",result.c_str());
}
int main()
{
	while(scanf("%s%s",x,y) != -1)
		fruits(x,y);
	return 0;
}
