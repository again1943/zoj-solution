#include<cstdio>
using namespace std;

#define SIZE 501

long long num[SIZE];

void set()
{
	num[0] = 1;		
	for( int j = 1; j < SIZE; j++ )	
	for( int i = SIZE-1; i >= j; i-- )
		num[i] += num[i-j];
}

int main()
{
	int n;
	set();
	while( scanf("%d",&n) && n != 0 )
		printf("%lld\n",num[n]-1);		
	return 0;
}
