#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAX_ELEM 1024
using namespace std;

int series[MAX_ELEM];

int unique_series(int& n)
{
	int s,e,m,maxlen = -1;
	for( s = 0,m = 1,e = 1; e < n; e++ )
	{
		if( series[e] == series[s] )
			m += 1;
		else
		{
			series[++s] = series[e];
			maxlen = max(m,maxlen);
			m  = 1;
		}
	}
	n = s+1;
	return max(maxlen,m);
}

int max_series(int n)
{
	int i,j,maxlen;
	int step,next,m;
	maxlen = unique_series(n);

	for( i = 0; i < n; i++ )
	for( j = i+1; j < n; j++ )
	{
		step = series[j]-series[i];
		next = series[j]+step;
		m = 2;
		while(binary_search(series+j,series+n,next) == true )
		{
			m += 1;
			next += step;
		}
		maxlen = max(m,maxlen);
	}
	return maxlen;
}


int main()
{
	int n,i;
	while(scanf("%d",&n) != -1)
	{
		for( i = 0; i < n; i++ )
			scanf("%d",&series[i]);
		sort(series,series+n);
		printf("%d\n",max_series(n));
	}
	return 0;
}