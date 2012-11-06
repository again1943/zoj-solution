#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define NUM 50
int num[NUM+5];
int temp[NUM+5];
void operation( int p, int c)
{
	memmove(temp,num+1,sizeof(int)*(p-1));
	memmove(num+1,num+p,sizeof(int)*c);
	memmove(num+c+1,temp,sizeof(int)*(p-1));
}
int main()
{
	int n,r,i,p,c;
	while(scanf("%d%d",&n,&r) && n != 0 )
	{
		for( i = 1; i <= n; i++ )
			num[i] = n-i+1;
		for( i = 0; i < r; i++ )
		{
			scanf("%d%d",&p,&c);
			operation(p,c);
		}
		printf("%d\n",num[1]);
	}
	return 0;
}
