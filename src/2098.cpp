#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define MAX_BALL 64
int M[MAX_BALL];
int P[MAX_BALL];
int time[MAX_BALL];

double pick_ball( int n,int t,int k )
{
	int i,j;
	double ret = 1;
	for( i = 0; i < t; i++ )							
	{
		if( P[i] > M[i] )
			return 0;
		if( P[i] == 0 || P[i] == M[i] )
			continue;
		for( j = 2; j <= M[i]; j++ )
			time[j] += 1;
		for( j = 2; j <= P[i]; j++ )
			time[j] -= 1;
		for( j = 2; j <= M[i]-P[i]; j++ )
			time[j] -= 1;
	}
	for( i = 2; i <= n; i++ )
		time[i] -= 1;
	for( i = 2; i <= k; i++ )
		time[i] += 1;
	for( i = 2; i <= n-k; i++ )
		time[i] += 1;
	for( i = 2; i <= n; i++ )
		ret *= pow((double)i,time[i]);
	return ret;
}

int main()
{
	int n,k,i,total;	
	while( scanf("%d%d",&n,&k) && ( n >= 0 && k >= 0 ))
	{
		for( i = total = 0; i < n; i++ )
		{
			scanf("%d",&M[i]);
			total += M[i];
		}
		for( i = 0; i < n; i++ )
			scanf("%d",&P[i]);
		memset(time,0,sizeof(time));
		printf("%0.5lf\n",(k<=total?pick_ball(total,n,k):0));
	}
	return 0;
}
