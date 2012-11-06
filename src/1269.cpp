#include<cstdio>
using namespace std;

int get_people( int n )
{
	int i,j;
	int copy;
	for( i = 10; i >= 2; i-- ) 		
	{
		copy = n;
		for( j = 0; j < i && copy > 0; j++ )	
		{
			if( copy % i == 1 )
				copy -= (copy-1)/i+1;
			else
				break;
		}
		if( j == i && copy%i == 0 )
			return i;
	}
	return -1;
}
int main()
{
	int n,r;	
	while(scanf("%d",&n) && n != -1 )
	{
		if( (r = get_people(n)) > 0 )
			printf("%d coconuts, %d people and 1 monkey\n"
				,n,r);
		else
			printf("%d coconuts, no solution\n",n);
	}
	return 0;
}
