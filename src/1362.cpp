#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
#define M 20
#define N 50
bitset<M*N+1>bit_set;
int cards[N];

int find_bigger( int p, int n )
{
	int i;
	for( i = p+1; i <= n; i++ )
		if( bit_set[i] == true )
			return i;
	return -1;	
}

int main()
{
	int t = 0;
	int i,m,n,c,p;
	
	while( scanf("%d%d",&m,&n) && m != 0 )
	{
		bit_set.set();
		for( i = 0; i < n; i++ )
		{
			scanf("%d",&cards[i]);
			bit_set[cards[i]] = false;
		}
		sort(cards,cards+n);	
		for( i = c = 0; i < n; i++ )
		{
			if( (p = find_bigger(cards[i],m*n)) < 0 )
				c += 1;
			else
				bit_set[p] = false;	
		}
		printf("Case %d: %d\n",++t,c);
	}
	return 0;
}
