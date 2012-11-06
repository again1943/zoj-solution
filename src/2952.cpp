#include<cstdio>
#include<algorithm>
#include<functional>
using namespace std;
#define MAX_ARRAY 65535
const unsigned long long LIMIT  = 2147483648LL;
unsigned long long set[MAX_ARRAY];

int main()
{
	int i,j,index,last;
	unsigned long long temp;
	for( i = 2,index = 0; i <= 46341; i++ )
	{
		temp = i*i;	
		while(temp < LIMIT )
		{
			set[index++] = temp;	
			temp *= i;
		}
	}
#ifdef DEBUG
	printf("Start Debug\n");
	last = set[0];
	printf("%lld\n",set[0]);

	for( i = 1; i < index; i++ )
	{
		if( set[i] != last )
		{
			last = set[i];
			printf("%lld\n",set[i]);
		}
	}
	printf("End Debug\n");
#endif
	sort(set,set+index);
	last = set[0];
	printf("%lld\n",set[0]);
	for( i = 1; i < index; i++ )
	{
		if( set[i] != last )
		{
			last = set[i];
			printf("%lld\n",set[i]);
		}
	}
	return 0;
}
