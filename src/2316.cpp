#include<cstdio>
#include<algorithm>
using namespace std;
#define SIZE 10002

int nodes[SIZE];

int main()
{
	int n,m;	
	int x,y;
	int result;
	int test_case;
	scanf("%d",&test_case);
	for( int i = 0; i < test_case; i++ )
	{
		result = 0;
		scanf("%d%d",&n,&m);
		fill(nodes,nodes+n+1,0);

		for( int j = 0; j < m; j++)
		{
			scanf("%d%d",&x,&y);
			nodes[x]++;
			nodes[y]++;
		}
		for( int j = 1; j <= n; j++ )
			result += nodes[j]*nodes[j];
		if( i == 0 )
			printf("%d\n",result);
		else
			printf("\n%d\n",result);

	}
	return 0;
}
