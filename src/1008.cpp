#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 32

int tetravex[MAXN][4];
int pcount[MAXN];
int gnome[MAXN];

using namespace std;


bool dfs(int s, int m, int n)
{
	int i,p;

	if( s == n * n )
		return true;
	for( i = 0; i < m; i++ )
	{
		if( pcount[i] <= 0 )
			continue;
		if( s/n > 0 )
		{
			p = gnome[s-n];
			if( tetravex[p][2] != tetravex[i][0] )
				continue;
		}
		if( s%n > 0 )
		{
			p = gnome[s-1];
			if(tetravex[p][1] != tetravex[i][3] )
				continue;
		}
		pcount[i] -= 1;
		gnome[s] = i;
		if( dfs(s+1,m,n) == true )
			return true;
		pcount[i] += 1;
	}
	return false;
}

int main()
{
	int n,i,a,b,c,d,k,m,j;
	k = 0;
	while(scanf("%d",&n) && n != 0)
	{
		memset(pcount,0,sizeof(pcount));
		for( i = m = 0; i < n*n; i++ )
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			for( j = 0; j < m; j++ )
				if( tetravex[j][0] == a && 
					tetravex[j][1] == b && 
					tetravex[j][2] == c &&
					tetravex[j][3] == d )
					break;
			if( j >= m )
			{
				tetravex[m][0] = a;
				tetravex[m][1] = b;
				tetravex[m][2] = c;
				tetravex[m][3] = d;
				pcount[m++]  = 1;
			}
			else
				pcount[j] += 1;
		}
		if( k != 0 )
			printf("\n");
		printf("Game %d: %s\n",++k,((dfs(0,m,n)==true)?"Possible":"Impossible"));
	}
	return 0;
}