#include<cstdio>
#include<cstring>
#include<bitset>
#include<cmath>
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

int tobig( char* bignum, int* big,int* times,int n )
{
	int i,ret,idx,count;
	int len = strlen(bignum);
	for( i = ret = idx = count = 0; bignum[i] != 0 ; i++ )
	{
		ret  = ret*10+bignum[i]-'0';	
		if( (++count) % n == 0 )
		{
			big[idx] = ret;
			times[idx++] = (int)pow((double)10,n);
			ret = 0;
		}
	}
	if( len%n != 0 )
	{
		big[idx] = ret;
		times[idx++] = (int)pow((double)10,len%n);
	}
	return idx;
}

int main()
{
	long long ret;
	int L,i,j,len;
	bool result;
	int idx = 0;
	int big[32];
	int times[32];
	len = fill_prime(prime,PRIME_LEN);
	while( scanf("%s%d",bignum,&L) && L != 0 )
	{
		idx = tobig( bignum,big,times,9);
		for( i = 0,result = true; i < len && prime[i] < L; i++ )
		{
			for( j = 0,ret = 0; j < idx; j++ )
				ret = (ret*times[j]+big[j])%prime[i];
			if( ret == 0 )
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

