#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_POOL 35000
#define MAX_N 3001
int lucky[MAX_N];
int a[MAX_POOL];
int b[MAX_POOL];
int init()
{
	int idx = 0;
	int *x,*y;
	int xidx,yidx,i;
	for( i = 2,xidx = 0; i < MAX_POOL; i++ )
		a[xidx++] = i;
	x = a;
	y = b;
	while( xidx > 0 )
	{
		yidx = 0;	
		lucky[idx++] = x[0];			
		for( i = 1; i < xidx; i++ )	
		{
			if( i % x[0] != 0 )			
				y[yidx++] = x[i];	
		}
		swap(x,y);
		xidx = yidx;
	}
	return idx;
}

int main()
{
	int idx = init();	
	int n;
	while( scanf("%d",&n) && n != 0 )
		printf("%d\n",lucky[n-1]);
	return 0;
}
