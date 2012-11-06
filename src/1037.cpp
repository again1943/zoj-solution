#include<cstdio>
using namespace std;

int main()
{
	int x,y,i,n;
	scanf("%d",&n);
	for( i = 1; i <= n; i++ )
	{
		scanf("%d%d",&x,&y);
		x *= y;
		if( x & 1 )
			printf("Scenario #%d:\n%d.41\n\n",i,x);
		else
			printf("Scenario #%d:\n%d.00\n\n",i,x);
	}
	return 0;
}
