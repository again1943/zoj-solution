#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define CASH_KIND 11
#define CASH_AMNT 100001

struct cash_t
{
	int n,v;	
}cash[CASH_KIND];

int available[CASH_KIND][CASH_AMNT];
int depth( int total,int n)
{
	int i,temp,ret;
	if( n <= 0 || total <= 0 )
		return 0;
	if( available[n][total] >= 0 )
		return available[n][total];
	for( i = 0; i <= cash[n-1].n; i++ )
	{
		if ((temp = total - i*cash[n-1].v)>= 0)
		{
			ret = depth(temp, n-1);
			available[n][total] = max(available[n][total],
				ret + i*cash[n-1].v);
		}
	}
	return available[n][total];
}

int main()
{
	int total,n,i;	
	while(scanf("%d",&total) != -1)
	{
		scanf("%d",&n);	
		for( i = 0; i < n; i++ )
			scanf("%d%d",&cash[i].n,&cash[i].v);
		memset(available,-1,sizeof(available));
		if( n == 0 || total == 0 )
			printf("0\n");	
		else
			printf("%d\n",depth(total,n));
	}
	return 0;
}
