#include<cstdio>
using namespace std;
#define MAX_SIZE 1000001
int count[MAX_SIZE];

//x%2 == 0
// f[x] = f[x+1] = f[x-1]+f[x/2];
int main()
{
	int i,n,t;	
	count[0] = 1;
	for( i = 1; i < MAX_SIZE; i++)
		count[i] = (count[i-1]+count[i>>1])%1000000;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%d",&t);
		printf("%d\n",count[t>>1]);
	}
	return 0;
}
