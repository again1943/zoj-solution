#include <cstdio>
#include <cstdlib>

#define MAXN 512

int bitmap[MAXN][MAXN];
int output[MAXN][MAXN];

int main()
{
	int n,i,j;
	int t = 0;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
			scanf("%d",&bitmap[i][j]);
		for( i = 0; i < n; i++ )
		{
			output[0][i] = bitmap[0][i];
			output[n-1][i] = bitmap[n-1][i];
		}
		for( i = 1; i < n-1; i++ )
		{
			output[i][0] = bitmap[i][0];
			output[i][n-1] = bitmap[i][n-1];
		}
		for( i = 1; i < n-1; i++ )
		for( j = 1; j < n-1; j++ )
			output[i][j] = (
							(bitmap[i-1][j-1]+bitmap[i+1][j+1]+bitmap[i-1][j+1]+bitmap[i+1][j-1])+
							((bitmap[i-1][j]+bitmap[i+1][j]+bitmap[i][j-1]+bitmap[i][j+1])<<1)+
							(bitmap[i][j]<<2)
							)>>4;
		printf("Case %d:\n",++t);
		for( i = 0; i < n; i++ )
		{
			printf("%d",output[i][0]);
			for( j = 1; j < n; j++ )
				printf(" %d",output[i][j]);
			printf("\n");
		}
	}
	return 0;
}