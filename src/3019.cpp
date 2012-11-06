#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 10004
using namespace std;

int order[2][MAXN];

int main()
{
	int i,j,m,n,c,p;
	int *x,*y;
	while(scanf("%d%d",&m,&n) != -1)
	{
		for( i = 0; i < m; i++ )
			scanf("%d",&order[0][i]);
		for( j = 0; j < n; j++ )
			scanf("%d",&order[1][j]);
		x = m > n?order[0]:order[1];
		y = m > n?order[1]:order[0];
		i = j = p = 0;

		sort(order[0],order[0]+m);
		sort(order[1],order[1]+n);

		while( j < min(m,n) && i < max(m,n) )
		{
			if( x[i] == y[j] )
			{
				p += 1;
				i += 1;
				j += 1;
			}
			else if( x[i] < y[j] )
				i += 1;
			else
				j += 1;
		}
		printf("%d\n",p);
	}
	return 0;
}