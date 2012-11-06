#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

int cubic( int n )
{
	int i,j,t,k,minval;
	for( i = 1,minval = 0x7fffffff; i <= n/2; i++ )	
	{
		if( n % i == 0 )
		{
			t = n/i;	
			for( j = i; j <= t/2; j++ )
			{
				if( t%j == 0 )
				{
					k = t/j;
					minval = std::min(minval,(i*j+i*k+t)*2);
				}
			}
		}
	}
	return minval;
}
int main()
{
	int n,k,i;	
	scanf("%d",&k);
	for( i = 0; i < k; i++ )
	{
		scanf("%d",&n);
		printf("%d\n",(n==1)?6:cubic(n));
	}
	return 0;
}
