#include<cstdio>
#include<cstring>
using namespace std;
#define SIZE 25

void do_cal( int* P, int* W, int n )
{
	int sum,i,j;
	int idx = 0;
	int pos = 0;
	int paren[2*SIZE];

	for( i = 0; i < P[0]; i++ )	
		paren[i] = 1;
	paren[P[0]] = -1;

	for( i = 1,idx = P[0]+1; i < n; i++ )
	{
		for( j = 1; j <= P[i]-P[i-1]; j++ )	
			paren[idx++] = 1;
		paren[idx++] = -1;
	}
	for( i = idx-1,pos = n-1; i >= 0; i-- )
	{
		if( paren[i] == -1 )	
		{
			for( sum = -1,j = i-1; sum != 0 ; j-- )
				sum += paren[j];
			W[pos--] = (i-j+1)/2;
		}
	}
}

int main()
{
	int t,n;
	int P[SIZE],W[SIZE];
	scanf("%d",&t);
	for( int i = 0; i < t; i++ )
	{
		scanf("%d",&n);
		for( int j = 0; j < n; j++ )
			scanf("%d",&P[j]);
		do_cal(P,W,n);		

		printf("%d",W[0]);
		for( int j = 1; j < n; j++ )
			printf(" %d",W[j]);	
		printf("\n");
	}
	return 0;
}
