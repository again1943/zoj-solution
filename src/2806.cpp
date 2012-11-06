#include<cstdio>
#include<cstring>
#include<bitset>
#include<cstdlib>
using namespace std;
#define PRIME_LEN 1000001
#define PRIME_CNT 80000
#define BIGNUM_LEN 102
int prime[PRIME_CNT];
bitset<PRIME_LEN> bit_set;
char bignum[BIGNUM_LEN];
int fill_prime(int* prime, int n)
{
	int i,j;
	int idx = 0;
	bit_set.set();
	for( i = 2; i < n; i++ )
	{
		if( bit_set[i] == true )
		{
			prime[idx++] = i;
			for( j = 2; j*i < n; j++ )
				bit_set[j*i] = false;
		}
	}
	return idx;
}
bool diviable( char* bignum, int n )
{
	int i;
	int ret = 0;
	for( i = 0; bignum[i] != 0; i++ )
		ret = (ret*10+bignum[i]-'0')%n;
	return (ret == 0);
}

int main()
{
	int L,i;
	int len;
	bool result;
	len = fill_prime(prime,PRIME_LEN);
	while( scanf("%s%d",bignum,&L) && L != 0 )
	{
		for( i = 0,result = true; i < len && prime[i] < L; i++ )	
		{
			if( diviable(bignum,prime[i]) == true )
			{
				result = false;
				break;
			}
		}
		if( result == true )
			printf("GOOD\n");
		else
			printf("BAD %d\n",prime[i]);
	}
	return 0;
}
