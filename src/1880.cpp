#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define PEOPLE_CNT 104
#define MAX_HALF_WEIGHT 22508
int weight[PEOPLE_CNT];
bool matrix[PEOPLE_CNT/2][MAX_HALF_WEIGHT]; 

int DP( int n, int wt )
{
	int i,j,w;
	memset(matrix,false,sizeof(matrix));
	matrix[0][0] = true;
	for( i = 1; i <= n; i++ )
	for( j = (n+1)/2; j >= 1; j-- )
	for( w = wt; w >= weight[i]; w-- )
		if( matrix[j][w] != true && matrix[j-1][w-weight[i]] == true )
			matrix[j][w] = true;
	for( i = wt; i >= 1; i-- )
		if( matrix[n/2][i] == true || matrix[(n+1)/2][i] == true )
			break;
	return i;
}

int main()
{
	int n,i,total,ret;
	while( scanf("%d",&n) != -1 )
	{
		for(i = 1,total = 0; i <= n; i++ )
		{
			scanf("%d",&weight[i]);
			total += weight[i];
		}
		ret = DP(n,total/2);
		printf("%d %d\n",ret,total-ret);
	}
	return 0;
}
