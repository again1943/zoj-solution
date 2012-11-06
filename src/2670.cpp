#include<cstdio>
using namespace std;

int main()
{
	int n,i,j;	
	while( scanf("%d",&n) != -1 )
	{
		for( i = 0; i < n-1; i++ )	
		{
			printf("0");
			for( j = 1; j < n; j++ )
				printf(" 0");
			printf("\n");
		}
		printf("0");
		for( i = 1; i < n-1; i++ )
			printf(" 0");
		printf(" 1\n\n");
	}
	return 0;
}
