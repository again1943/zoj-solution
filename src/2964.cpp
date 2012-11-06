#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
#define MAXN 65536

vector<int> primes;

void fill_primes(vector<int>& pm)
{
	int i,j;
	char touch[MAXN];
	memset(touch,1,sizeof(touch));

	touch[0] = touch[1] = 0;
	for( i = 2; i < MAXN/2+1; i++ )
	{
		if( touch[i] != 1 )
			continue;
		for( j = 2; i*j < MAXN; j++ )
			touch[i*j] = 0;
	}
	for( i = 2; i < MAXN; i++ )
		if( touch[i] == 1 )	
			pm.push_back(i);

}

void defact(int z,vector<int>& factor)
{
	int i;
	int m = (int)sqrt((double)z) + 1;
	for( i = 0; i < (int)primes.size() && primes[i] < m; i++ )
	{
		if( z % primes[i] != 0 )
			continue;
		factor.push_back(primes[i]);
		while( z != 1 &&  z % primes[i] == 0 )
			z /= primes[i];
		if( z == 1 )
			break;
	}
	if( z != 1 )
		factor.push_back(z);
}

long long power_module(int a, int b, int c)
{
	long long v;
	if( b == 0 )
		return 1LL;
	else if( b == 1 )
		return a%c;
	v = power_module(a,b/2,c)%c;	
	v = (v*v)%c;
	if( b % 2 != 0 )
		v = (v*a)%c;
	return v;
}

long long triangle(int a, int z)
{
	int i,v,m,mt;
	vector<int> factor;			

	defact(z,factor);
	for( i = 0,v = z; i < (int)factor.size(); i++ )
	{
		v /= factor[i];	
		v *= factor[i]-1;
	}

	m = (int)sqrt((double)v)+1;
	mt = v;
	for( i = 2; i < m; i++ )
	{
		if( v % i != 0 )		
			continue;
		if( power_module(a,i,z) == 1 )
		{
			mt = i;
			break;
		}
		if( power_module(a,v/i,z) == 1 )
			mt = v/i;
	}
	return mt;
}
int main()
{
	int a,z,k,i;

	fill_primes(primes);

	scanf("%d",&k);
	for( i = 0; i < k; i++ )
	{
		scanf("%d%d",&a,&z);
		if( a == 1 || z == 1 )
			printf("9\n");
		else
			printf("%lld\n",6*triangle(a,z)+3);
	}
	return 0;
}
