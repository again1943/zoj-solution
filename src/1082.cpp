#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_CNT 128
#define MAX_INF 0x12345
int matrix[MAX_CNT][MAX_CNT];

int max( int value[], int n )
{
	int i;
	int maxidx = -1;
	int maxval = 0;
	for( i = 0; i < n; i++ )
	{
		if( value[i] > maxval )
		{
			maxidx = i;
			maxval = value[i];
		}
	}
	return maxidx;
}
int main()
{
	int minval,minidx,maxidx;
	int n,i,j,k,c,t,time;	
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )	
		{
			fill(matrix[i],matrix[i]+n,MAX_INF);	
			matrix[i][i] = 0;
			scanf("%d",&c);
			for( j = 0; j < c; j++ )
			{
				scanf("%d%d",&t,&time);
				matrix[i][t-1] = time;
			}
		}
		for( k = 0; k < n; k++ )
		for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
			matrix[i][j] = min(matrix[i][j],matrix[i][k]+matrix[k][j]);
		for( i = 0,minval = MAX_INF; i < n; i++ )
		{
			maxidx = max(matrix[i],n);
			if( minval > matrix[i][maxidx] )
			{
				minval = matrix[i][maxidx];
				minidx = i;
			}
		}
		if( minval >= MAX_INF )
			printf("disjoint\n");
		else
			printf("%d %d\n",minidx+1,minval);
	}
	return 0;
}
