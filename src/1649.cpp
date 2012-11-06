#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
#define N 201
#define M 201

struct pos_t
{
	int x,y;
	pos_t()
	{
		x = y = -1;
	}
	pos_t( int x_, int y_ )
	{
		x = x_;
		y = y_;
	}
};

char maze[N][M];
pos_t pending[N*M];
int time_stamp[N][M];



inline bool inside( int x, int y, int n, int m )
{
	return (x >= 0 && x < n && y >= 0 && y < m );
}

int offset[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};

bool enqueue( queue<pos_t>& Q,int n, int m ,int& guard,pos_t& pos )
{
	int x, y,i;
	for( i = 0; i < 4; i++ )
	{
		x = pos.x + offset[i][0];
		y = pos.y + offset[i][1];
		if( inside(x,y,n,m) && time_stamp[x][y] == -1 )
		{
			switch(	maze[x][y] )
			{
				case 'a':
					return true;	
				case '#':
					time_stamp[x][y] = -2;	
					break;
				case '.':
					time_stamp[x][y] = time_stamp[pos.x][pos.y]+1;	
					Q.push(pos_t(x,y));
					break;
				default: //for 'x'
					pending[guard].x = x;
					pending[guard++].y = y;
					time_stamp[x][y] = -2;	
					break;
			}
		}
	}
	return false;
}

int bfs( int n, int m )
{
	int i,j,t;
	int guard;
	pos_t pos;
	queue<pos_t> Q;	
	memset(time_stamp,-1,sizeof(time_stamp));

	for( i = 0; i < n; i++ )
	for( j = 0; j < m; j++ )
	{
		if( maze[i][j] == 'r' )
		{
			pos.x = i;
			pos.y = j;
			Q.push(pos);
			time_stamp[i][j] = 0;
		}
	}
	
	t = 0;
	guard = 0;
	while( Q.empty() != true || guard != 0)
	{
		if( Q.empty() == true )
		{
			while( --guard >= 0 )
			{
				Q.push(pending[guard]);
				time_stamp[pending[guard].x][pending[guard].y] = t+2;
			}
			guard = 0;
			pos = Q.front();				
			Q.pop();
			t = t+2;
		}
		else
		{
			pos = Q.front();				
			Q.pop();
			if( t != time_stamp[pos.x][pos.y] )
			{
				t = time_stamp[pos.x][pos.y];		
				while( --guard >= 0 )
				{
					Q.push(pending[guard]);
					time_stamp[pending[guard].x][pending[guard].y] = t+1;
				}
				guard = 0;
			}
		}
		if( enqueue(Q,n,m,guard,pos) == true )
			return t+1;
	}
	return -1;
}

int main()
{
	int i,n,m,t;
	while( scanf("%d%d",&n,&m) != -1 )
	{
		for( i = 0; i < n; i++ )	
			scanf("%s",maze[i]);
		if( (t = bfs( n,m )) < 0 )
			printf("Poor ANGEL has to stay in the prison all his life.\n");
		else
			printf("%d\n",t);
	}
	return 0;
}
