#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXN 64
bool in[MAXN];
int queue[2][MAXN];

bool bfs( int n, int m )
{
	int i,item,b;
	int *x = queue[0];
	int *y = queue[1];
	int a = 1;
	int step = 3;
	x[0] = 1;

	if( m == 1 )
		return true;
	while( 1 )	
	{
		memset(in,false,sizeof(in));
		for( i = b = 0; i < a; i++ )
		{
			if( (item = x[i] + step) <= n &&
				in[item] != true )		
			{
				y[b++] = item;
				in[item] = true;
				if( item == m )
					return true;
			}
			if( (item = x[i] - step ) >= 1 &&
				in[item] != true )
			{
				y[b++] = item;
				in[item] = true;
				if( item == m )
					return true;
			}
		}
		if( b == 0 )
			return false;
		swap(x,y);
		a = b;
		b = 0;
		step += 2;
	}
	return false;
}
int main()
{
	int n,m;		
	while( scanf("%d%d",&n,&m) && n != 0 )
	{
		if( n > 50 )
			printf("Let me try!\n");
		else
			printf("%s\n",bfs(n,m)?"Let me try!":
					"Don't make fun of me!");
	}
	return 0;
}
