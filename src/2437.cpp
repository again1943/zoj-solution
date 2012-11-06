#include <queue>
#include <cmath>
#include <cstdio>
#include <utility>
#include <cstdlib>
#include <cstring>

#define MAX_SIZE 204
int matrix[MAX_SIZE][MAX_SIZE];
int replace[MAX_SIZE][MAX_SIZE];

inline bool inside( int x, int y, int n )
{
	return (x >= 0 && x < n && y >= 0 && y < n);
}
int search( int x, int y, int n )
{
	int near,ret;
	int d, a, b;
	for( d = 1; d <= 2*n; d++ )
	{
		near = 0;	
		a = x;
		b = y-d;
		if( inside(a,b,n) && matrix[a][b] != 0 )
		{
			near += 1;	
			ret  = matrix[a][b];
		}
		b = y+d;
		if( inside(a,b,n) && matrix[a][b] != 0 )
		{
			near += 1;
			if( near > 1 )
				return 0;
			ret = matrix[a][b];
		}
		for( b = y-d+1; b <= y+d-1; b++ )
		{
			a = d-abs(b-y)+x;
			if( inside(a,b,n) && matrix[a][b] != 0 )
			{
				near += 1;
				if( near > 1 )
					return 0;
				ret  = matrix[a][b];
			}
			a = abs(b-y)+x-d;
			if( inside(a,b,n) && matrix[a][b] != 0 )
			{
				near += 1;
				if( near > 1 )
					return 0;
				ret = matrix[a][b]; 
			}
		}
		if( near == 1 )
			return ret;
	}
	return -1;
}
inline void bfs( int n )
{
	int i,j;
	for( i = 0; i < n; i++ )
	for( j = 0; j < n; j++ )
		replace[i][j] = ((matrix[i][j] != 0 )?matrix[i][j]:search(i,j,n));
}
inline void print(int m[][MAX_SIZE], int n)
{
	int i,j;
	for( i = 0; i < n; i++ )	
	{
		printf("%d",m[i][0]);
		for( j = 1; j < n; j++ )		
			printf(" %d",m[i][j]);
		printf("\n");
	}
}
int main()
{
	bool allzero;
	int t,i,j,k,n;	
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d",&n);
		allzero = true;
		for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
		{
			scanf("%d",&matrix[i][j]);
			if( matrix[i][j] != 0 )
				allzero = false;
		}
		if( k != 0 )
			printf("\n");
		if( allzero == true )
			print(matrix,n);
		else
		{
			bfs(n);	
			print(replace,n);
		}
	}
	return 0;
}
