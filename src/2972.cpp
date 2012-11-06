#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX_VALUE 112
int TIME[MAX_VALUE][3];
int FORCE[MAX_VALUE][2];
int table[MAX_VALUE][MAX_VALUE];

#define INF 999999

int dp(int n, int m)
{
	int i,j,c,d;
	for( i = 0; i <= n; i++ )
	for( j = 0; j <= m; j++ )
		table[i][j] = INF;
	table[0][m] = 0;
	for( i = 1; i <= n; i++)
	for( j = 0; j <= m; j++)
	{
		if( (c = j-FORCE[i][0]) >= 0
			&& table[i][c] > (d = table[i-1][j]+TIME[i][0]))
			table[i][c] = d;
		if( table[i][j] > (d = table[i-1][j]+TIME[i][1]))
			table[i][j] = d;
		if( (c = j+FORCE[i][1]) >= m && table[i][m] > (d = table[i-1][j]+TIME[i][2]))
			table[i][m] = d;
		if( c < m && table[i][c] > (d = table[i-1][j]+TIME[i][2]))
			table[i][c] = d;
	}
	for( i = 0,c = INF; i <= m; i++ )
			c = std::min(c,table[n][i]);
	return c;
}
int main()
{
	int t,k,n,m,i;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d%d",&n,&m);
		for( i = 1; i <= n; i++ )
		{
			scanf("%d%d%d%d%d",&TIME[i][0],&TIME[i][1],&TIME[i][2],&FORCE[i][0],&FORCE[i][1]);
		}
		printf("%d\n",dp(n,m));
	}
	return 0;
}