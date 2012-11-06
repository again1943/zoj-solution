#include<cstdio>
using namespace std;
int main()
{
	int X[3];
	int i;
	while( scanf("%d%d%d",X,X+1,X+2 ) != EOF )
	{
		for( i = 0; i < 3; i++ )
			if( X[i] <= 168 )
				break;
		if( i < 3 )
			printf("CRASH %d\n",X[i]);
		else
			printf("NO CRASH\n");
	}
	return 0;
}
