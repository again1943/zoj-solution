#include<cstdio>
#include<algorithm>
using namespace std;
#define HORSE_CNT 1024
int A[HORSE_CNT],B[HORSE_CNT];

int main()
{
	int n,i,as,ae,bs,be,win;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )	
			scanf("%d",&A[i]);
		for( i = 0; i < n; i++ )
			scanf("%d",&B[i]);
		sort(A,A+n);
		sort(B,B+n);
		as = bs = 0;
		ae = be = n-1;
		for( i = win = 0; i < n; i++ )
		{
			if( A[as] < B[bs] ){as++;be--;win--;}
			else if( A[as] > B[bs] ){as++;bs++;win++;}
			else if( A[ae] > B[be] ){ae--;be--;win++;}
			else if( A[ae] < B[be] ){as++;be--;win--;}
			else if( A[as] < B[be] ){as++;be--;win--;} 
		}
		printf("%d\n",win*200);
	}
	return 0;
}
