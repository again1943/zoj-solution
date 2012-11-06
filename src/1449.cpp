#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 32
int cubic[MAXN][MAXN][MAXN];
int cubsum[MAXN][MAXN][MAXN];
int main()
{
	int i,j,k,n,m,r,s,t,tmp;
	while( scanf("%d",&n) && n != 0 )
	{
		memset(cubic,0,sizeof(cubic));
		memset(cubsum,0,sizeof(cubsum));
		for( i = 1; i <= n; i++ )
		for( j = 1; j <= n; j++ )
		for( k = 1; k <= n; k++ )
		{
			scanf("%d",&cubic[i][j][k]);
			cubsum[i][j][k] = cubic[i][j][k]+cubsum[i-1][j][k]+
					cubsum[i][j-1][k]+cubsum[i][j][k-1]-
					cubsum[i][j-1][k-1]-cubsum[i-1][j-1][k]-
					cubsum[i-1][j][k-1]+cubsum[i-1][j-1][k-1];
		}
		m = cubsum[1][1][1];
		//tmp = max(cubsum[1][1][2],max(cubsum[1][2][1],cubsum[2][1][1]));
		//m = (tmp+cubsum[1][1][1],tmp);
		for( i = 1; i <= n; i++ )
		for( j = 1; j <= n; j++ )
		for( k = 1; k <= n; k++ )
		for( r = 1; r <= i; r++ )
		for( s = 1; s <= j; s++ )
		for( t = 1; t <= k; t++ )
		{
			tmp = cubsum[i][j][k]-cubsum[r-1][s-1][t-1]-
				cubsum[r-1][j][k]-cubsum[i][s-1][k]-
				cubsum[i][j][t-1]+cubsum[r-1][s-1][k]+
				cubsum[r-1][j][t-1]+cubsum[i][s-1][t-1];
			m = max(tmp,m);
		}
		printf("%d\n",m);
	}
	return 0;
}