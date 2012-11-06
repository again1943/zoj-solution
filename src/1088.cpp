#include<cstdio>
#define SIZE 151
using namespace std;

bool build[150];

bool is_right( int m, int n )
{
	int stop =  1;
	for( int i = 1; i <= n; i++ )
		build[i] = false;
	build[1] = true;
	int i = 1;
	int tick = 0;
	while( 1 )
	{
		i = (i+1) > n ? 1:i+1;
		if( build[i] == false )
			tick++;
		if( tick == m )
		{
			stop++;
			tick = 0;
			if( i == 2 )
				return false;
			else
			{
				if( stop == n-1 )
					return true;
				else 
					build[i] = true;
		
			}
		}	
	}
}
int result( int n )
{
	int m = 2;
	while( is_right( m,n ) != true )
		m++;
	return m;
}
int main()
{
	int num;
	scanf("%d",&num);
	while ( num != 0 )
	{
		printf("%d\n",result(num));
		scanf("%d",&num);
	}
	return 0;
}
