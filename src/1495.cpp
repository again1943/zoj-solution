#include<cstdio>
using namespace std;
#define RING_CNT 128
int rings[RING_CNT];

int main()
{
	int n,i,lower;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )	
			scanf("%d",&rings[i]);
		for( i = 0,lower = n; i < n; i++ )
		{
			if( rings[i] < lower )	
				lower = rings[i]-1;
			else
				lower -= 1;
			if( lower < 1 )
				break;
		}
		printf("%d\n",n-i-1);
	}
	return 0;
}
