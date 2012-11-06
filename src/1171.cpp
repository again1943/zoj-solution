#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
	char c,last;
	int i,t,n,test_case,count;
	scanf("%d",&test_case);
	for( t = 0; t < test_case; t++ )
	{
		if( t != 0 )
			printf("\n");
		scanf("%d",&n);
		i = count = 0;	
		last = 0;
		while( i < n )
		{
			c = getchar();
			if( c == 'U' || c == 'D' )
			{
				i += 1;
				if( last != 0 && last != c )
					count++;
				last = c;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
