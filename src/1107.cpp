#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
#define GRID_SIZE 101

struct grid_t
{
	int v, tv;
};

struct pos_t
{
	int x,y;
	pos_t():x(-1),y(-1)
	{}
	pos_t(int x_,int y_):x(x_),y(y_)
	{}
};

bool   inqueue[GRID_SIZE][GRID_SIZE];
grid_t grid[GRID_SIZE][GRID_SIZE];

inline bool inside( int x, int y, int n)
{
	return (x >= 0 && x < n && y >= 0 && y < n);	
}
int bfs( int n,int k )
{
	int step,x,y,value;
	int max_value;
	pos_t item;
	queue<pos_t> Q;
	max_value = grid[0][0].v;
	grid[0][0].tv = grid[0][0].v;
	memset(inqueue,0,sizeof(inqueue));

	Q.push(pos_t(0,0));
	while( Q.empty() != true )
	{
		item = Q.front();	
		Q.pop();
		inqueue[item.x][item.y] = false;
		for( step = 1; step <= k; step++ )	
		{
			x = item.x+step;
			y = item.y;
			if( inside(x,y,n) && grid[item.x][item.y].v < grid[x][y].v &&
				(value = grid[item.x][item.y].tv+grid[x][y].v) > grid[x][y].tv )
			{
				grid[x][y].tv = value;
				max_value = max(max_value,value);
				if( inqueue[x][y] == false )
				{
					Q.push(pos_t(x,y));
					inqueue[x][y] = true;
				}
			}
			x = item.x-step;
			y = item.y;
			if( inside(x,y,n) && grid[item.x][item.y].v < grid[x][y].v &&
				(value = grid[item.x][item.y].tv+grid[x][y].v) > grid[x][y].tv )
			{
				grid[x][y].tv = value;
				max_value = max(max_value,value);
				if( inqueue[x][y] == false )
				{
					Q.push(pos_t(x,y));
					inqueue[x][y] = true;
				}
			}
			x = item.x;
			y = item.y+step;
			if( inside(x,y,n) && grid[item.x][item.y].v < grid[x][y].v &&
				(value = grid[item.x][item.y].tv+grid[x][y].v) > grid[x][y].tv )
			{
				grid[x][y].tv = value;
				max_value = max(max_value,value);
				if( inqueue[x][y] == false )
				{
					Q.push(pos_t(x,y));
					inqueue[x][y] = true;
				}
			}
			x = item.x;
			y = item.y-step;
			if( inside(x,y,n) && grid[item.x][item.y].v < grid[x][y].v &&
				(value = grid[item.x][item.y].tv+grid[x][y].v) > grid[x][y].tv )
			{
				grid[x][y].tv = value;
				max_value = max(max_value,value);
				if( inqueue[x][y] == false )
				{
					Q.push(pos_t(x,y));
					inqueue[x][y] = true;
				}
			}
		}
	}
	return max_value;
}

int main()
{
	int n,k,i,j;	
	while(scanf("%d%d",&n,&k) && n != -1 )
	{
		for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
		{
			scanf("%d",&grid[i][j].v);
			grid[i][j].tv = 0;
		}
		printf("%d\n",bfs(n,k));
	}
	return 0;
}

