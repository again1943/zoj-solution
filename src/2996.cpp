#include <cstdio>


int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k) != -1)
	{
		if( n == 0 && k == 0 )
			printf("1\n");
		else
			printf("%d\n",((n&k) == k?1:0));
	}
	return 0;
}