#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>


using namespace std;

#define MAXN 64

bool taken[MAXN][MAXN][4];
int maze[MAXN][MAXN];

int turn[4][2] = {{1,3},{0,2},{1,3},{0,2}};
int step[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int revs[4] = {2,3,0,1};

struct queue_item_t
{
	short int x,y,time,dir;
};
int dir_num(char* dir)
{
	if( strcmp(dir,"east") == 0 )
		return 0;
	else if( strcmp(dir,"south") == 0 )
		return 1;
	else if( strcmp(dir,"west") == 0 )
		return 2;
	else if( strcmp(dir,"north") == 0 )
		return 3;
	else
		return -1;
}

inline bool inside(int x, int y, int m, int n)
{
	return (x>=0 && x < m && y >= 0 && y < n);
}
int bfs(int m, int n, int sx, int sy, int tx, int ty, char* dir)
{
	int x,y,i,d;
	queue<queue_item_t> Q;
	queue_item_t item,next;

	if( sx == tx && sy == ty )
		return 0;

	memset(taken,0,sizeof(taken));
	item.dir = dir_num(dir);
	item.time = 0;
	item.x = sx;
	item.y = sy;
	taken[sx][sy][item.dir] = true;
	Q.push(item);

	while(Q.empty() != true)
	{
		item = Q.front();
		Q.pop();

		next.time = item.time+1;
		next.dir = item.dir;

		for( i = 1; i <= 3; i++ )
		{
			x = item.x+step[item.dir][0]*i;
			y = item.y+step[item.dir][1]*i;

			if( inside(x,y,m,n) != true || inside(x+1,y+1,m,n) != true )
				break;
			if( maze[x][y] != 0 || maze[x+1][y] != 0
				||maze[x][y+1] != 0 || maze[x+1][y+1] != 0 )
				break;
			if( taken[x][y][item.dir] == true )
				continue;
			if( x == tx && y == ty )
				return next.time;
			next.x = x;
			next.y = y;
			taken[x][y][item.dir]  = true;
			Q.push(next);
		}
		next = item;
		next.time  = item.time+1;
		for( i = 0; i < 2; i++ )
		{
			d = turn[item.dir][i];
			if( taken[next.x][next.y][d] != true )
			{
				next.dir = turn[item.dir][i];
				Q.push(next);
				taken[next.x][next.y][d] = true;
			}
		}

	}
	return -1;
}
int main()
{
	int m,n,i,j;
	int sx,sy,tx,ty;
	char dir[16];
	while(scanf("%d%d",&m,&n) && m != 0)
	{
		for( i = 0; i < m; i++ )
			for( j = 0; j < n; j++ )
				scanf("%d",&maze[i][j]);
		scanf("%d%d%d%d%s",&sx,&sy,&tx,&ty,dir);
		printf("%d\n",bfs(m,n,sx-1,sy-1,tx-1,ty-1,dir));
	}
	return 0;
}
