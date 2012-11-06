#include<cstdio>
#include<algorithm>
using namespace std;
#define MAX_SIZE 70000
#define BOUND 1000000000000000000LL
long long int elem[MAX_SIZE];

int prime[] = {2,3,5,7};
int humble( long long int bound )
{
	int n = 2;
	int i,minidx;
	long long int minval,item;
	int record[] = {1,1,1,1};

	elem[0] = 0;
	elem[1] = 1;
	while( elem[n-1] < bound )
	{
		minval = 0x7fffffffffffffffLL;
		for( i = 0; i < 4; i++ )
		{
			//while(binary_search(elem,elem+n,(item = prime[i]*elem[record[i]])) == true )
			while( (item = prime[i]*elem[record[i]]) <= elem[n-1] )
				record[i] += 1;
			if( minval > item )
			{
				minidx = i;	
				minval = item;
			}
		}
		elem[n++] = minval;
		record[minidx] += 1;
	}
	return n;
}

int main()
{
	int i,n,test_case;
	scanf("%d",&test_case);	
	humble(BOUND);
	for( i = 0; i < test_case; i++ )
	{
		scanf("%d",&n);
		printf("%lld\n",elem[n]);
	}
	return 0;
}
