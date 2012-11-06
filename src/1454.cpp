#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

#define MAXN 16
#define INVALID 0x7fffffff
int worker[MAXN];
int prev[2048];
int next[2048];

int dp(int n, int hire,int fire,int salary,int m1,int m2)
{
	int i,j,k,cost,ret;
	int *x = prev;
	int *y = next;
	for( i = m1; i <= m2; i++ )
	{
		if( i < worker[0] )
			x[i-m1] = INVALID;
		else
			x[i-m1] = i*salary+hire*i;
	}
	for( i = 1; i < n; i++ )
	{
		for( j = m1; j <= m2; j++ )
		{
			y[j-m1] = INVALID;
			if( j < worker[i] )
				continue;
			else
			{
				for( k = m1; k <= m2; k++ )
				{
					if( x[k-m1] != INVALID )
					{
						cost = j*salary+((k > j)?fire*(k-j):hire*(j-k))+x[k-m1];
						y[j-m1] = min(y[j-m1],cost);
					}
				}
			}
		}
		swap(x,y);
	}
	for( i = m1,ret = INVALID; i <= m2; i++ )
		ret = min(x[i-m1],ret);
	return ret;
}
int main()
{
	int month,i,m1,m2;
	int fire,hire,salary;
	while(scanf("%d",&month) && month != 0)
	{
		scanf("%d%d%d",&hire,&salary,&fire);
		m2 = 0;
		m1 = 0x7fffffff;
		for( i = 0; i < month; i++ )
		{
			scanf("%d",&worker[i]);
			m1 = min(worker[i],m1);
			m2 = max(worker[i],m2);
		}
		printf("%d\n",dp(month,hire,fire,salary,m1,m2));
	}
	return 0;
}
