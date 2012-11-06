#include<cstdio>
using namespace std;

int main()
{
	int n;	
	int a,b,c,d,count,current;
	while( scanf("%d",&n) != -1 )
	{
		count = 1;
		scanf("%d",&current);	
		for( int i = 1; i < n; i++ )
		{
			scanf("%d",&x);
			if( x == current )
				count++;
			else
			{
				count--;
				if( count < 0 )
				{
					current = x;
					count = 1;
				}
			}
		}
		printf("%d\n",current);
	}
	return 0;
}
