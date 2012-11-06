#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define MAXN 65536

char maze[8][8];
bool touch[MAXN];

struct elem_t
{
	int time;
	int state;
	elem_t():time(0),state(0)
	{}
	elem_t(int t, int s):time(t),state(s)
	{}
};
int mask[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int table[16][6] = 
{
	{2,1,4},{3,0,2,5},{3,1,3,6},{2,2,7},
	{3,0,5,8},{4,1,4,6,9},{4,2,5,7,10},{3,3,6,11},
	{3,4,9,12},{4,5,8,10,13},{4,6,9,11,14},{3,7,10,15},
	{2,8,13},{3,9,12,14},{3,10,13,15},{2,11,14}
};
int state()
{
	int ret = 0;
	for( int i = 0; i < 4; i++ )
		for( int j = 0; j < 4; j++ )
		{
			if( maze[i][j] == 'b' )//'b' is marked as 1
				ret |= mask[i*4+j];
		}
	return ret;
}

inline int inverse(int code, int pos)
{
	return (code^mask[pos]);
}
int bfs( int start )
{
	int c,i,j;
	elem_t item;
	queue<elem_t>Q;
	memset(touch,0,sizeof(touch));
	touch[start] = true;
	Q.push(elem_t(0,start));
	while( Q.empty() != true)
	{
		item = Q.front();
		Q.pop();
		if( item.state == 0 || item.state == 65535 )
			return item.time;
		for( i = 0; i < 16; i++ )
		{
			c = inverse(item.state,i);
			for( j = 0; j < table[i][0]; j++)
				c = inverse(c,table[i][j+1]);
			if( touch[c] != true )
			{
				touch[c] = true;
				Q.push(elem_t(item.time+1,c));
			}
		}
	}
	return -1;
}
int main()
{
	int n,t,i,ret;
	scanf("%d",&n);
	for( t = 0; t < n; t++ )
	{
		if( t != 0 )
			printf("\n");
		for( i = 0; i < 4; i++)
			scanf("%s",maze[i]);
		if((ret = bfs(state())) < 0 )
			printf("Impossible\n");
		else
			printf("%d\n",ret);
	}
	return 0;
}
