#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define NODE_CNT 25
#define EDGE_CNT 4
bool edge[NODE_CNT][NODE_CNT];
bool edgecpy[NODE_CNT][NODE_CNT];
struct node_t
{
	int cnt;	
	int adj[EDGE_CNT];
}G[NODE_CNT];

int bfs( int s )
{
	int e,ret,i;
	int maxlen = 0;	
	//node[s] = true;	
	for( i = 0; i < G[s].cnt; i++ )
	{
		e = G[s].adj[i];
		if( edgecpy[s][e] == true )
		{
			edgecpy[s][e] = edgecpy[e][s] = false;	
			ret = bfs(e);
			maxlen = max(maxlen,ret+1);
			edgecpy[s][e] = edgecpy[e][s] = true;
		}
	}
	return maxlen;
}
int main()
{
	int n,m,i;
	int s,e,maxlen,ret;
	while( scanf("%d%d",&n,&m) && n != 0 )	
	{
		memset(G,0,sizeof(G));
		for( i = 0; i < m; i++ )	
		{
			scanf("%d%d",&s,&e);
			G[s].adj[G[s].cnt++] = e;
			G[e].adj[G[e].cnt++] = s;
			edge[s][e] = edge[e][s] = true;
		}
		for( i = 0,maxlen = 0; i < n; i++ )
		{
			memcpy(edgecpy,edge,sizeof(edge));
			if((ret = bfs(i)) > maxlen )	
				maxlen = ret;	
		}
		printf("%d\n",maxlen);
	}
	return 0;
}
