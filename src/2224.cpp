#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define MAX_ELEM 16
#define MAX_INT 50000
int value[16];
int interest[16];

int maxint[MAX_INT];
void calc(int e)
{
	int maxval = 0;
	int i,j,tmp;
	//memset(maxint,0,sizeof(maxint));
	for( i = 0; i < MAX_INT; i++ )
	{
		maxint[i] = maxval;
		for( j = 0; j < e; j++ )
		{
			tmp = i-value[j]/1000;
			if( tmp >= 0 )
				maxint[i] = max(maxint[i],maxint[tmp]+interest[j]);
		}
		maxval = max(maxval,maxint[i]);
	}
}
int doit(int n, int d, int e)
{
	int i,ret;
	calc(e);
	for( i = 0,ret = n; i < d; i++ )
		ret += maxint[ret/1000];
	return ret;
}
int main()
{
	int n,d,e,k,t,i;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d%d%d",&n,&d,&e);
		for( i = 0; i < e; i++ )
			scanf("%d%d",&value[i],&interest[i]);
		printf("%d\n",doit(n,d,e));
	}
	return 0;
}