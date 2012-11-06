#include<cstdio>
using namespace std;

int tickets[10001];

inline void set( int n )
{
	for( int i = 1; i <= n; i++ )	
		tickets[i] = -1;
}

int main()
{
	int m,n;
	int count;
	int temp;

	scanf("%d%d",&n,&m);

	while( m != 0 || n != 0 )
	{
		set(n);	
		count = 0;
		
		for( int i = 0; i < m;i++ )
		{
			scanf("%d",&temp);
			tickets[temp]++;
		}

		for( int i = 1; i <= n; i++ )
			if( tickets[i] >= 1 )
				count++;
		printf("%d\n",count);
		scanf("%d%d",&n,&m);

	}

	return 0;
}
