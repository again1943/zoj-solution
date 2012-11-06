#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define SIZE 1001

bool prime[SIZE];
int prime_count[SIZE];
int prime_set[SIZE];

int set()
{
	int k = (int)sqrt((double)(SIZE))+1;
	prime[0] = false;
	std::fill(prime+1,prime+SIZE,true);
	for( int i = 2; i < k; i++ )
	{
		if( prime[i] == true )
		{
			for( int j = i; i*j < SIZE; j++ )
				prime[i*j] = false;
		}
	}

	int prime_num = 0;
	prime_count[0] = 0;

	for( int i = 1; i < SIZE; i++ )
	{
		if(prime[i] == true )
		{
			prime_count[i] = prime_count[i-1]+1;
			prime_set[prime_num++] = i;	
		}
		else
			prime_count[i] = prime_count[i-1];
	}
	return prime_num;
}


int main()
{
	int n,c;	
	int num;
	set();
	while( scanf("%d%d",&n,&c) != -1 )
	{
		num = prime_count[n];		
		printf("%d %d:",n,c);
		if( num % 2 == 0 )
		{
			if( num > 2*c )
			{
				for( int i = num/2-c; i < num/2+c; i++ )
					printf(" %d",prime_set[i]);	
			}
			else
			{
				for( int i = 0; i < num; i++ )
					printf(" %d",prime_set[i]); 
			}
		}
		else
		{
			if( num > 2*c-1 )
			{
				for( int i = (num+1)/2-c; i < (num+1)/2+c-1; i++ )
					printf(" %d",prime_set[i]);	
			}
			else
			{
				for( int i = 0; i < num; i++ )
					printf(" %d",prime_set[i]); 
			}
		
		}
		printf("\n\n");
	}
	return 0;
}
