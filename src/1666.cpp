#include<cstdio>
#include<algorithm>
#define SIZE 301
#define ELEM 17
int main()
{
	int n,k;
	int count[SIZE];
	
	count[0] = 1;
	std::fill(count+1,count+SIZE,0);
	for( int i = 1; i <= ELEM; i++)
	{
		k = i*i;
		for( int j = 0; j < SIZE; j++)		
			if( j+k < SIZE )
				count[j+k] += count[j];
	}
	while( scanf("%d",&n) && n != 0 )
		printf("%d\n",count[n]);
	return 0;
}
