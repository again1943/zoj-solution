#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
#define MAX_SIZE 31

char incrz[][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};
int time_stamp[MAX_SIZE][MAX_SIZE][MAX_SIZE];
char cubic[MAX_SIZE][MAX_SIZE][MAX_SIZE];

struct pos_t
{
	int x,y,z;
	pos_t()
	{
		x = y = z = 0;
	}
	pos_t( int x_, int y_, int z_ )
	{
		x = x_;	
		y = y_;
		z = z_;
	}
};

bool inside( pos_t& pt,int L, int R, int C)
{
	return (pt.x >= 0 && pt.x < L && 
		pt.y >= 0 && pt.y < R &&
		pt.z >= 0 && pt.z < C);
}

void find_start( pos_t& start,int L, int R, int C )
{
	int i,j,k;
	for( i = 0; i < L; i++ )
	for( j = 0; j < R; j++ )
	for( k = 0; k < C; k++ )
		if( cubic[i][j][k] == 'S' )
			start = pos_t(i,j,k);
}

int bfs( pos_t& start, int L,int R,int C )
{
	int i,m;
	pos_t cur,pt;
	queue<pos_t> pos;
	memset(time_stamp,-1,sizeof(time_stamp));

	pos.push(start);
	time_stamp[start.x][start.y][start.z] = 0;	
	while( pos.empty() != true )
	{
		cur = pos.front();
		pos.pop();
		m = time_stamp[cur.x][cur.y][cur.z];
		if( cubic[cur.x][cur.y][cur.z] == 'E' )
			return m;
		for( i = 0; i < 6; i++ )
		{
			pt = pos_t(cur.x + incrz[i][0],
				cur.y + incrz[i][1],cur.z + incrz[i][2]);
			if( inside( pt,L,R,C) == true && 
				cubic[pt.x][pt.y][pt.z] != '#'&&
				time_stamp[pt.x][pt.y][pt.z] < 0 )
			{
				pos.push(pt);	
				time_stamp[pt.x][pt.y][pt.z] = m+1;
			}
		}
	}
	return -1;
}

int main()
{
	int i,j,m;
	int L,R,C;
	pos_t start;
	while(scanf("%d%d%d",&L,&R,&C) && L != 0 )
	{
		for( i = 0; i < L; i++ )	
		for( j = 0; j < R; j++ )
			scanf("%s",cubic[i][j]);
		find_start(start,L,R,C);
		if( (m = bfs(start,L,R,C)) < 0 )
			printf("Trapped!\n");
		else
			printf("Escaped in %d minute(s).\n",m);
	}
	return 0;
}
