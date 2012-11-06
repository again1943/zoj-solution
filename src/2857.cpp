#include<cstdio>
using namespace std;

#define SIZE 100

int img[SIZE][SIZE];

int main()
{
	int x,y;
	int temp;
	int iter = 0;
	while( scanf("%d%d",&x,&y) && ( x > 0 && y > 0 ))
	{
		for( int i = 0; i < x; i++ )	
		for( int j = 0; j < y; j++ )
			scanf("%d",&img[i][j]);
		for( int i = 0; i < x; i++ )	
		for( int j = 0; j < y; j++ )
		{
			scanf("%d",&temp);
			img[i][j] += temp;
		}
		for( int i = 0; i < x; i++ )	
		for( int j = 0; j < y; j++ )
		{
			scanf("%d",&temp);
			img[i][j] += temp;
		}
		printf("Case %d:\n",++iter);
		for( int i = 0; i < x; i++ )
		{
			printf("%d",img[i][0]/3);
			for( int j = 1; j < y; j++ )
				printf(",%d",img[i][j]/3);
			printf("\n");
		}
	}
	return 0;
}
