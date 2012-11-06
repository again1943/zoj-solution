#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define MAZE_SIZE 8 
char line[MAZE_SIZE];
bool maze[MAZE_SIZE][MAZE_SIZE];
int direct[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

inline bool inside( int x, int y,int n, int m)
{
	return (x >= 0 && x < n && y >= 0 && y < m );	
}
bool dfs( int x, int y, int dx, int dy, int n, int m, int T,int step)
{
	int i,tx,ty;
	if(step == T )
		return ( x == dx && y == dy );
	else
	{
		maze[x][y] = false;
		for( i = 0; i < 4; i++ )	
		{
			tx = x+direct[i][0];
			ty = y+direct[i][1];
			if( inside(tx,ty,n,m) && maze[tx][ty] && dfs(tx,ty,dx,dy,n,m,T,step+1))
				return true;
		}
		maze[x][y] = true;
		return false;
	}
}
bool test( int x, int y, int dx,int dy, int n, int m, int T,int space)
{
	if( space+1 < T || abs(abs(dx-x)+abs(dy-y)-T)%2 != 0 )
		return false;
	else
		return dfs(x,y,dx,dy,n,m,T,0);
}
int main()
{
	int x,y,dx,dy,space;
	int i,j,n,m,T;
	while(scanf("%d%d%d",&n,&m,&T) && n != 0 )
	{
		space = 0;
		for( i = 0; i < n; i++ )
		{
			scanf("%s",line);
			for( j = 0; j < m; j++ )
			{
				switch( line[j] )
				{
					case 'X':
						maze[i][j] = false;	
						break;
					case 'S':
						maze[i][j] = true;
						x = i;
						y = j;
						break;
					case 'D':
						maze[i][j] = true;
						dx = i;
						dy = j;
						break;
					default:
						space++;
						maze[i][j] = true;
						break;
				}
			}
		}
		printf("%s\n",test(x,y,dx,dy,n,m,T,space)?"YES":"NO");
	}
	return 0;
}
