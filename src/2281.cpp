#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 100002

int weight[MAXN];
vector<pair<int,int> >graphics[MAXN];

struct comp
{
	bool operator()(const pair<int,int>&a,const pair<int,int>& b)
	{
		return a.second < b.second;
	}
};

int freedom(int s,int e, int n, int m)
{
	int i,x,y,w;
	pair<int,int>item;
	priority_queue<pair<int,int>,vector<pair<int,int> >,comp>Q;

	memset(weight,-1,sizeof(weight));
	for( i = 0; i < (int)graphics[s].size(); i++ )
	{
		y = graphics[s][i].first;
		Q.push(make_pair(y,graphics[s][i].second));
		weight[y] = graphics[s][i].second;
		
	}
	while( Q.empty() != true )
	{
		item = Q.top();
		Q.pop();
		for( x = item.first,i = 0; i < (int)graphics[x].size(); i++ )
		{
			if( x == e )
				return item.second;
			
			y = graphics[x][i].first;
			if( y == s )
				continue;
		
			if( (w = min(item.second,graphics[x][i].second)) > weight[y])
			{
				weight[y] = w;
				Q.push(make_pair(y,w));
			}
		}
	}
	return 0;
}
int main()
{
	int n,m,x,y,w,i;
	while(scanf("%d%d",&n,&m) != -1)
	{
		for( i = 0; i < m; i++ )
		{
			scanf("%d%d%d",&x,&y,&w);
			graphics[x].push_back(make_pair(y,w));
			graphics[y].push_back(make_pair(x,w));
		}
		scanf("%d%d",&x,&y);
		printf("%d\n",freedom(x,y,n,m));
		for( i = 0; i < n; i++ )
			graphics[i].clear();
	}
	return 0;
}