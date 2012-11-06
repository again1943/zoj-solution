#include<cstdio>
#include<cstdlib>
using namespace std;
#define CARD_CNT 25

int card[2][CARD_CNT];

int main()
{
	int t = 0;
	int A,B,n,i;
	while(scanf("%d",&n) && n != 0)
	{
		if( t++ != 0 )
			printf("\n");
		for( i = 0; i < n; i++ )	
			scanf("%d",&card[0][i]);
		for( i = 0; i < n; i++ )	
			scanf("%d",&card[1][i]);
		for( A = B = i = 0; i < n; i++ )
		{
			if( card[0][i] != card[1][i] )
			{
				if( card[0][i] - card[1][i] > 1 )
					A += card[0][i];
				else if( card[0][i] - card[1][i] < -1 )
					B += card[1][i];
				else if( card[0][i] - card[1][i] == 1 )
					B += (card[0][i]==2)?6:card[0][i]+card[1][i];
				else
					A += (card[1][i]==2)?6:card[0][i]+card[1][i];
			}
		}
		printf("A has %d points. B has %d points.\n",A,B);
	}
	return 0;
}


