#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>


using namespace std;
#define MAXN 12

int maze[MAXN][MAXN];
int taken[MAXN][MAXN];

int step[4][2] ={{0,-1},{0,1},{-1,0},{1,0}};

struct queue_elem_t
{
	int x,y;
	int hp,tm;
};
bool inline inside(int x, int y, int m, int n)
{
	return (x >= 0 && x < m && y >= 0 && y < n);
}
void find_start(int m, int n,int& sx,int& sy)
{
	int i,j;
	for( i = 0; i < m; i++ )
	for( j = 0; j < n; j++ )
	{
		if( maze[i][j] == 2)
		{
			sx = i;
			sy = j;
			return;
		}
	}
}
int walk_ants(int m,int n)
{
	int i,x,y,sx,sy,hp,tm;
	queue_elem_t item,next;
	queue<queue_elem_t>Q;

	find_start(m,n,sx,sy);

	if( maze[sx][sy] == 3 )
		return 0;

	memset(taken,0,sizeof(taken));
	item.hp = 6;
	item.tm = 0;
	item.x = sx;
	item.y = sy;
	taken[sx][sy] = 6;
	Q.push(item);
	
	while(Q.empty() != true)
	{
		item = Q.front();
		Q.pop();

		for( i = 0; i < 4; i++ )
		{
			x = item.x+step[i][0];
			y = item.y+step[i][1]; 
			hp = item.hp - 1;
			tm = item.tm + 1;
			if( inside(x,y,m,n) != true || maze[x][y] == 0 || hp <= taken[x][y] )
				continue;
			if( maze[x][y] == 3 )
				return tm;
			next.x = x;
			next.y = y;
			next.tm = tm;
			if( maze[x][y] == 1 )//empty
			{
				next.hp = hp;
				taken[x][y] = hp;
				Q.push(next);
			}
			if( maze[x][y] == 4) //food here
			{
				next.hp = 6;
				taken[x][y] = 6;
				Q.push(next);
			}
		}
	}
	return -1;
}
int main()
{
	int m,n,i,j;
	while(scanf("%d%d",&n,&m)  && m != 0)
	{
		for( i = 0; i < m; i++ )
		for( j = 0; j < n; j++ )
			scanf("%d",&maze[i][j]);
		printf("%d\n",walk_ants(m,n));
	}
	return 0;
}