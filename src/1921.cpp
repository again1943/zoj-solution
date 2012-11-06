#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAX_LINE 128

char prev[MAX_LINE][MAX_LINE];
char next[MAX_LINE][MAX_LINE];
int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
inline bool inside(int x, int y, int n, int m)
{
	return (x >= 0 && x < n && y >= 0 && y < m);	
}
inline bool at(char a, char b)
{
	return ((a == 'R' && b == 'S')||
		(a == 'S' && b == 'P')||
		(a == 'P' && b == 'R'));
}

bool action(char prev[][MAX_LINE], char next[][MAX_LINE], int n, int m)
{
	bool s;
	int i,j,k,x,y;
	for( i = 0,s = true; i < n; i++ )
	for( j = 0; j < m; j++ )
	{
		next[i][j] = prev[i][j];
		for( k = 0; k < 4; k++ )
		{
			x = i+step[k][0];		
			y = j+step[k][1];
			if( !inside(x,y,n,m))
				continue;
			if( at(prev[x][y],prev[i][j]) == true )
			{
				next[i][j] = prev[x][y];
				s = false;
				break;
			}
		}
	}
	return s;
}
typedef char (*SP)[MAX_LINE];
inline SP work( char prev[][MAX_LINE], char next[][MAX_LINE], int n, int m, int c)
{
	int i;
	char (*a)[MAX_LINE] = prev;
	char (*b)[MAX_LINE] = next;
	for( i = 0; i < c; i++ )
	{
		if( action(a,b,n,m) == true )
			break;
		std::swap(a,b);
	}
	return a;
}
int main()
{
	char (*r)[MAX_LINE];
	int n, m, d,t,k,i;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d%d%d",&n,&m,&d);
		for( i = 0; i < n; i++ )
			scanf("%s",prev[i]);
		r = work(prev,next,n,m,d);		
		if( k != 0 )
			printf("\n");
		for( i = 0; i < n; i++ )
			printf("%s\n",r[i]);
	}
	return 0;
}
