#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;
#define MAX_WORD 12
#define MAX_ITEM 24

char words[MAX_ITEM][MAX_WORD];
int	 queue[2][MAX_ITEM];

int main()
{
	int t,k,n,m,i,x,y;
	scanf("%d",&k);
	for( t = 0; t < k; t++ )
	{
		scanf("%d%d",&m,&n);
		for( i = 0; i < m; i++ )
		{
			scanf("%s",words[i]);
			queue[0][i] = i;
		}
		memset(queue[1],-1,sizeof(queue[1]));
		for( i = 0; i < n; i++ )
		{
			scanf("%d%d",&x,&y);
			queue[1][y-1] = queue[0][x-1];
			queue[0][x-1] = -1;
		}
		x = y = 0;

		while( x < m && y < m )
		{
			if( queue[1][y]  < 0 )
			{
				while( x < m && queue[0][x] < 0 )
					x += 1;
				queue[1][y] = queue[0][x];
				x += 1;
			}
			y += 1;
		}
		printf("%s",words[queue[1][0]]);
		for( i = 1; i < m; i++ )
			printf(" %s",words[queue[1][i]]);
		printf("\n");
	}
	return 0;
}