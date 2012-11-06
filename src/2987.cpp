#include <cstdio>

int main()
{
	char c;
	int n,k,i,j;
	scanf("%d",&n);
	for( i = 1; i <= n; i++ )
	{
		j = 0;
		scanf("%d",&k);	
		printf("%d",i);
		while((c = getchar()) != '\n')		
		{
			if( j++ != k )
				putchar(c);
		}
		putchar('\n');
	}
	return 0;
}
