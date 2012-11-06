#include<cstdio>
using namespace std;

#define MAX_ORDER 24
int coeff[MAX_ORDER];

int main()
{
	int i,j,n,order;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		if( i != 0 )
			printf("\n");
		scanf("%d",&order);
		for( j = 0; j <= order; j++ )
			scanf("%d",&coeff[j]);
		if( order <= 1 || 
			(order == 2 && coeff[1]*coeff[1]-4*coeff[0]*coeff[2] < 0 ))
			printf("YES\n");
		else 
			printf("NO\n");
	}
	return 0;
}
