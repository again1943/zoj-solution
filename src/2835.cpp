#include<cstdio>
#include<algorithm>
using namespace std;

int m[10][10];
bool size[1001];

bool test_range( int n )
{
	if( n == 1 )
		return true;
	fill( size+1,size+1001,false);
	for( int i = 0; i < n; i++ )
	for( int j = 0; j < n; j++ )
	{
		if( size[m[i][j]] == true )	
			return false;
		size[m[i][j]] =  true;
	}
	return true;
}

bool test_row( int row,int average,int n)
{
	int temp = 0;
	for( int i = 0; i < n; i++ )
		temp += m[row][i];
	if( temp == average )
		return true;
	else
		return false;
}
bool test_col( int col,int average,int n)
{
	int temp = 0;
	for( int i = 0; i < n; i++ )
		temp += m[i][col];
	if( temp == average )
		return true;
	else
		return false;
}
bool test_dia( int average,int n)
{
	int temp_1st = 0;
	int temp_2st = 0;
	for( int i = 0; i < n; i++)	
	{
		temp_1st += m[i][i];	
		temp_2st += m[i][n-i-1];
	}
	if( temp_1st != average )
		return false;
	if( temp_2st != average )
		return false;
	return true;
}
int main()
{
	int n,average;	
	int flag;
	while( scanf("%d",&n) && n > 0 )
	{
		for( int i = 0; i < n; i++ )
		for( int j = 0; j < n; j++ )
			scanf("%d",&m[i][j]);
		flag = true;
		if (test_range(n) == false )
		{
			flag = false;
			goto done;
		}
		average = 0;
		for( int i = 0; i < n; i++ )
			average += m[0][i];
		for( int i = 0; i < n; i++ )
			if( test_row(i,average,n) == false || test_col(i,average,n) == false )
			{
				flag = false;
				goto done;
			}
		if( test_dia(average,n) == false )
			flag = false;
		done:
			if( flag == true )
				printf("Yes\n");
			else
				printf("No\n");
	}
	return 0;
}
