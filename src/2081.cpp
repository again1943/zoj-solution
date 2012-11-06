#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
#define MAXN 12
char maze[MAXN][MAXN];
struct count_t
{
	unsigned int ts,tm;
};
count_t grid[MAXN][MAXN];


int transform_maze(int m, int n)
{
	int i,j,start;
	start = -1;
	memset(grid,0,sizeof(grid));
	for( i = 0; i < m; i++ )
	for( j = 0; j < n; j++ )
		if( maze[i][j] == 'S' )
			start = i*m+j;
	return start;
}

int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

inline bool inside(int x,int y, int m, int n)
{
	return (x >= 0 && x < m && y >=0 && y < n);
}

struct queue_elem_t
{
	short int x,y,d;
};

bool mission(int m,int n, double* possible)
{
	bool done;
	int x,y,start,i,x0,y0;
	start = transform_maze(m,n);
	queue_elem_t		item,next;
	queue<queue_elem_t> Q,M,*R,*S;

	item.d = 0;
	item.x = start/m;
	item.y = start%m;
	grid[item.x][item.y].ts = 1;
	R = &Q;
	S = &M;
	
	R->push(item);
	done = false;

	while(1)
	{
		while(R->empty() != true)
		{
			item = R->front();
			R->pop();

			for( i = 0; i < 4; i++ )
			{
				x = item.x+step[i][0];
				y = item.y+step[i][1];
				if( inside(x,y,m,n) != true )
					continue;
				switch(maze[x][y])
				{
				case 'M':
					next.d = item.d+1;
					next.x = x;
					next.y = y;
					if(grid[x][y].ts == 0 && grid[x][y].tm == 0)
						S->push(next);
					grid[x][y].tm += grid[item.x][item.y].tm+grid[item.x][item.y].ts;
					break;
				case ' ':
					next.d = item.d+1;
					next.x = x;
					next.y = y;
					if( grid[x][y].ts == 0 && grid[x][y].tm == 0)
						S->push(next);
					grid[x][y].ts += grid[item.x][item.y].ts;
					grid[x][y].tm += grid[item.x][item.y].tm;
					break;
				case 'T':
					done = true;
					x0 = x;
					y0 = y;
					grid[x][y].ts += grid[item.x][item.y].ts;
					grid[x][y].tm += grid[item.x][item.y].tm;
					break;
				default:
					break;
				}
			}
		}
		maze[item.x][item.y] = 'X';
		if( done == true )
		{
			if( grid[x0][y0].ts == 0 )
				return false;
			else
			{
				*possible = 1.0*grid[x0][y0].ts/(grid[x0][y0].ts+grid[x0][y0].tm);
				return true;
			}
		}
		if( S->empty() == true )
			return false;
		swap(R,S);
	}
}
int main()
{
	int		t,k,m,n,i;
	double	possible;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d%d",&m,&n);
		gets(maze[0]);
		for( i = 0; i < m; i++ )
			gets(maze[i]);
	/*	if( k != 0 )
			printf("\n");*/
		printf("Mission #%d:\n",k+1);
		if( mission(m,n,&possible) != true )
			printf("Mission Impossible.\n\n");
		else
			printf("The probability for the spy to get to the telegraph transmitter is %0.2lf%%.\n\n",possible*100);
		
	}
	return 0;
}