#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define DATA_LEN 1004
#define PRIME_LEN 10000
bool prime[PRIME_LEN];
bool mask[DATA_LEN];
int aprime[DATA_LEN];
void cal_prime()
{
	int i,j;
	memset(prime,1,sizeof(prime));	
	prime[0] = prime[1] = false;
	for( i = 2; i < PRIME_LEN/2+1; i++ )
	{
		if( prime[i] == true )
		{
			for( j = 2; i*j < PRIME_LEN; j++ )
				prime[i*j] = false;
		}
	}
}

bool test( int* aprime, int start,int depth )
{
	int i;
	int sum = aprime[start];
	for( i = start-1; i >= start-depth+1 && i >= 0; i-- )
	{
		sum += aprime[i];
		if( prime[sum] == true )
			return false;
	}
	return true;
}
bool dfs( int start, int end,int depth,int idx)
{
	int i;
	for( i = 0; start+i <= end; i++ )
	{
		if( mask[i] == true )	
		{
			aprime[idx] = start+i;		
			if( test(aprime,idx,depth) != true )
				continue;
			if( idx == end-start )
				return true;
			mask[i] = false;
			if( dfs(start,end,depth,idx+1) == true )
				return true;
			mask[i] = true;
		}
	}
	return false;
}

int main()
{
	int m,n,d,i;
	cal_prime();
	while( scanf("%d%d%d",&m,&n,&d) && m != 0 )
	{
		memset(mask,1,sizeof(mask));
		if( n-m+1 < d || dfs(m,n,d,0) == false )
			printf("No anti-prime sequence exists.\n");	
		else
		{
			printf("%d",aprime[0]);	
			for( i = 1; i <= n-m; i++ )
				printf(",%d",aprime[i]);
			printf("\n");
		}
	}
	return 0;
}
