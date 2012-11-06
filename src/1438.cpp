#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 12

struct STATE
{
	int x,y,z,t;
};

int tran[6][3] = 
{
	{0,0,-1},{0,0,1},
	{0,-1,0},{0,1,0},
	{-1,0,0},{1,0,0}
};
char cubic[MAXN][MAXN][MAXN];
bool touch[MAXN][MAXN][MAXN];

inline bool inside( int n, int x, int y, int z)
{
	return (x>= 0 && x < n && y >= 0 && 
		y < n && z >= 0 && z < n);
}

int bfs( int n, int x0, int y0, int z0, int x1, int y1, int z1)
{
	int i;
	STATE s, item,temp;
	queue<STATE>Q;
	s.x = x0;
	s.y = y0;
	s.z= z0;
	s.t = 0;
	memset(touch,0,sizeof(touch));
	touch[x0][y0][z0] = true;
	Q.push(s);
	while( Q.empty() != true )
	{
		item = Q.front();
		Q.pop();
		if( item.x == x1 && item.y == y1 && item.z == z1 )
			return item.t;
		for( i = 0; i < 6; i++ )
		{
			temp.x = item.x+tran[i][0];
			temp.y = item.y+tran[i][1];
			temp.z = item.z+tran[i][2];
			temp.t = item.t+1;
			if( inside(n,temp.x,temp.y,temp.z) == true &&
				cubic[temp.x][temp.y][temp.z] != 'X' &&
				touch[temp.x][temp.y][temp.z] != true )
			{
				touch[temp.x][temp.y][temp.z] = true;
				Q.push(temp);
			}
		}
	}
	return -1;
}
int main()
{
	char stm[32];
	int x0,y0,z0,x1,y1,z1,n,i,j,k,ret;
	while(scanf("%s%d",stm,&n) != -1)
	{
		for( k = 0; k < n; k++)
		for( j = 0; j < n; j++)
		{
			getchar();
			for( i = 0; i < n; i++)
			scanf("%c",&cubic[i][j][k]);
		}
		scanf("%d%d%d%d%d%d",&x0,&y0,&z0,&x1,&y1,&z1);
		scanf("%s",stm);
		if((ret = bfs(n,x0,y0,z0,x1,y1,z1)) < 0)
			printf("NO ROUTE\n");
		else
			printf("%d %d\n",n,ret);
	}
	return 0;
}