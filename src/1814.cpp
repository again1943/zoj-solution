#include<cstdio>
using namespace std;
#define CHILD_CNT 1024

int children[CHILD_CNT];
bool the_same( int* child,int n )
{
	for( int i = 1; i < n; i++ )
		if( child[0] != child[i] )
			return false;
	return true;
}
void next_round(int* child,int n)
{
	int i,t,next,temp;

	next = child[n-1];
	t = child[0]/2+next/2;
	child[n-1] = (t%2 == 0 )?t:t+1;
	
	for( i = n-2; i >= 0; i-- )
	{
		temp = child[i];
		t = child[i]/2+next/2;
		child[i] = ( t%2 == 0 )?t:t+1;
		next = temp;
	}
}
int main()
{
	int n,i,round;
	while(scanf("%d",&n) && n != 0)
	{
		for( i = 0; i < n; i++ )
			scanf("%d",&children[i]);
		round = 0;
		while( the_same(children,n) != true )
		{
			next_round(children,n);
			round++;
		}
		printf("%d %d\n",round,children[0]);
	}
	return 0;
}