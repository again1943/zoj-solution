#include<cstdio>
#include<queue>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;
#define INF_MAX 0x1234567

int matrix[8][8];
int cost[8][8][4];
int step[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

inline bool inside( int x, int y, int n )
{
	return (x >= 0 && x < n && y >= 0 && y < n);
}

struct qelem
{
	int pos,total,state;
	qelem():pos(-1),total(-1),state(-1)
	{};
	qelem(int pos_, int total_, int state_):pos(pos_),total(total_),state(state_)
	{}
};

int bfs( int start, int end )
{
	int* boring;
	int x,y,i,current,state;
	qelem item;
	queue<qelem>Q;	
	Q.push(qelem(start,0,0));
	cost[start/8][start%8][0] = 0;		

	while( Q.empty() != true )
	{
		item = Q.front();	
		Q.pop();
		for( i = 0; i < 4; i++ )	
		{
			x = step[i][0]+item.pos/8;	
			y = step[i][1]+item.pos%8;
			if( inside(x,y,8) )
			{
				current = matrix[x][y]*(item.state+1);
				state = current%4;	
				if( cost[x][y][state] > item.total + current )
				{
					cost[x][y][state] = item.total+current;	
					Q.push(qelem(x*8+y,cost[x][y][state],state));
				}
			}
		}
	}
	boring = cost[end/8][end%8];
	current = boring[0];	
	for( i = 1; i < 4; i++ )
		current = min(boring[i],current);
	return current;
}
int main()
{
	int sx, sy,ex,ey,i,j;
	while( scanf("%d%d%d%d",&sx,&sy,&ex,&ey) && 
		(sx != 0 || sy != 0 || ex != 0 || ey != 0 ))
	{
		memset(cost,-1,sizeof(cost));
		for( i = 0; i < 8; i++ )	
		for( j = 0; j < 8; j++ )
		{
			scanf("%d",&matrix[i][j]);
			cost[i][j][0] = cost[i][j][1] = cost[i][j][2] = cost[i][j][3] = INF_MAX;			
		}
		printf("%d\n",bfs((sx-1)*8+(sy-1),(ex-1)*8+(ey-1)));
	}
	return 0;
}
