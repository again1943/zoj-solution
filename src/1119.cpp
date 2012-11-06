#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define MAX_NRK 1024

int low[MAX_NRK];
int tindex[MAX_NRK];
int rtindex[MAX_NRK];
int subnet[MAX_NRK];
int touch[MAX_NRK];
bool network[MAX_NRK][MAX_NRK];

void dfs( int u,int n, int c)
{
	int i;
	low[u] = touch[u] = c;
	for(i = 0; i < n; i++)
	{
		if( network[u][i] == true )
		{
			if(touch[i] < 0)
			{
				dfs(i,n,c+1);
				low[u] = std::min(low[u],low[i]);
				if( low[i] >= touch[u])
					subnet[u]++;
			}
			else
				low[u] = std::min(low[u],touch[i]);
		}
	}
}
int main()
{
	bool flags;
	int t = 0;
	int x,y,n,a,b,i;
	while( scanf("%d",&x) && x != 0)
	{
		n = 0;
		scanf("%d",&y);
		memset(network,false,sizeof(network));
		memset(rtindex,-1,sizeof(rtindex));
		if( rtindex[x] == -1 )
		{
			tindex[n] = x;
			rtindex[x] = n++;
		}
		a = rtindex[x];
		if( rtindex[y] == -1 )
		{
			tindex[n] = y;
			rtindex[y] = n++;
		}
		b = rtindex[y];
		network[a][b] = network[b][a] = true;
		while( scanf("%d",&x) && x != 0 )
		{
			scanf("%d",&y);
			if( rtindex[x] == -1 )
			{
				tindex[n] = x;
				rtindex[x] = n++;
			}
			a = rtindex[x];
			if( rtindex[y] == -1 )
			{
				tindex[n] = y;
				rtindex[y] = n++;
			}
			b = rtindex[y];
			network[a][b] = network[b][a] = true;
		}
		memset(touch,-1,sizeof(touch));
		memset(low,-1,sizeof(low));
		memset(subnet,0,sizeof(subnet));
		dfs(0,n,1);
		if( subnet[0] != 0 )
			subnet[0]--;
		if( t != 0 )
			printf("\n");
		printf("Network #%d\n",++t);
		flags = true;
		for( i = 0; i < n; i++ )
			if( subnet[i] != 0 )
			{
				flags = false;
				printf("  SPF node %d leaves %d subnets\n",tindex[i],subnet[i]+1);
			}
			if( flags == true )
				printf("  No SPF nodes\n");
	}
	return 0;
}
