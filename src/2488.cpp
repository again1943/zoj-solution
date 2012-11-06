#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
#define MAX_ROPE 1024

int ropes[MAX_ROPE];

int main()
{
	int t,n,i,k,maxval;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d",&n);
		for( i = 0; i < n; i++ )
			scanf("%d",&ropes[i]);
		sort(ropes,ropes+n,greater<int>());
		for( i = maxval = 0; i < n; i++ )
			maxval = max(ropes[i]*(i+1),maxval);
		printf("%d\n",maxval);
	}
	return 0;
}
