#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 1000004
#define MAXP 47000
int		primes[MAXP];
bool	mark[MAXN];
bool	taken[MAXP];

int select_primes(int maxn)
{
	int i,j,nprimes,p;
	memset(taken,0,sizeof(taken));
	
	for( nprimes = 0,i = 2; i < MAXP; i++ )
	{
		if( taken[i] != true )
		{
			primes[nprimes++] = i;
			for( j = 2; (p = j*i) < MAXP; j++ )
				taken[p] = true;
		}
	}
	return nprimes;
}


bool prime_distance(int nprimes, long long left, long long right, 
					long long& a, long long& b, 
					long long& c, long long& d)
{
	long long i,j,start;
	long long p,m,n;
	
	memset(mark,0,sizeof(mark));
	for( i = 0; i < nprimes && i <= right; i++ )
	{
		start = (left+primes[i]-1)/primes[i];
		for( j = max(start,2LL); (p = j*primes[i]) <= right; j++ )
			mark[p-left] = true;
	}
	a = b = c = d = m = n = -1;
	for( p = left; p <= right; p++ )
	{
		if( mark[p-left] != true )
		{
			if( m < 0 )
				m = p;
			else
			{
				n = p;
				if( a < 0 || b - a > n - m )
				{
					a = m;
					b = n;
				}
				if( c < 0 || d - c < n - m )
				{
					c = m;
					d = n;
				}
				m = n;
			}
		}
	}
	return (a > 0);
}

int main()
{
	long long minx,miny,maxx,maxy;
	long long x,y;
	int n = select_primes(MAXP);
	while(scanf("%lld%lld",&x,&y) != -1)
	{
		x = max(x,2LL);
		if( prime_distance(n,x,y,minx,miny,maxx,maxy) != true )
			printf("There are no adjacent primes.\n");
		else
			printf("%lld,%lld are closest, %lld,%lld are most distant.\n",minx,miny,maxx,maxy);
	}
	return 0;
}