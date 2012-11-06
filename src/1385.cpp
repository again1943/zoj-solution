#include <cstdio>
int main()
{
	int n,m,i,d;	
	scanf("%d",&d);
	for( i = 0; i < d; i++ )
	{
		scanf("%d%d",&n,&m);
		//printf("%d\n",(((n-m)&((m-1)/2))==0?1:0));
		putchar((((n-m)&((m-1)/2))==0?'1':'0'));
		putchar('\n');
	}
	return 0;
}
