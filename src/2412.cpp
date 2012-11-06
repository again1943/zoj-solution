#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 64

bool touch[MAXN][MAXN];
char farm[MAXN][MAXN];
int direct[][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int opposite[] = {2,3,0,1};
bool pipe[][4] = 
{
	{1,0,0,1},{1,1,0,0},{0,0,1,1},{0,1,1,0},/*ABCD*/
	{1,0,1,0},{0,1,0,1},{1,1,0,1},{1,0,1,1},/*EFGH*/
	{0,1,1,1},{1,1,1,0},{1,1,1,1},/*IJK*/
};

inline bool inside( int x, int y, int n, int m )
{
	return ( x >= 0 && x < n && y >= 0 && y < m );
}

void dfs(char farm[][MAXN], int x, int y, int n, int m )
{
	int a,b,i,p;
	int idx = farm[x][y]-'A';			
	touch[x][y] = true;
	for( i = 0; i < 4; i++ )
	{
		if(pipe[idx][i] == false )
			continue;
		a = x+direct[i][0];	
		b = y+direct[i][1];
		p = opposite[i];
		if( inside(a,b,n,m) == true && touch[a][b] != true 
			&& pipe[farm[a][b]-'A'][p] == true )
			dfs(farm,a,b,n,m);
	}
}
int detail(char farm[][MAXN], int n, int m )
{
	int i,j;
	int count = 0;
	memset(touch,false,sizeof(touch));
	for( i = 0; i < n; i++ )	
	for( j = 0; j < m; j++ )
	{
		if( touch[i][j] == true )
			continue;
		count += 1;
		dfs(farm,i,j,n,m);
	}
	return count;
}
int main()
{
	int n,m,i;
	while( scanf("%d%d",&n,&m) && n > 0 )
	{
		for( i = 0; i < n; i++ )	
			scanf("%s",farm[i]);
		printf("%d\n",detail(farm,n,m));
	}
	return 0;
}
