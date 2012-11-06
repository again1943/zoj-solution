#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
#define MAXN 100000
#define INFINITY 2000000000

using namespace std;

int price[MAXN];
vector<pair<int,int> > matrix[MAXN];
vector<pair<int,int> > invmtx[MAXN];

int bellman_ford(int n, int m,vector<pair<int,int> >* mtx)
{
	int i,x,y,p;	
	pair<int,int>item;
	queue<int> relax;
	for( i = 1; i <= n; i++ )
		price[i] = INFINITY; 
	price[1] = 0;
	relax.push(1);

	while(relax.empty() != true)
	{
		x = relax.front();	
		relax.pop();
		for( i = 0; i < (int)mtx[x].size(); i++ )
		{
			item = mtx[x][i];
			y = item.first;
			if( price[y] > price[x]+item.second )
			{
				price[y] = price[x]+item.second;
				relax.push(y);
			}
		}
	}
	for( i = 1,p = 0; i <= n; i++ )
		p += price[i];
	return p;
}
int invitation_cards(int n, int m)
{
	return bellman_ford(n,m,matrix)+bellman_ford(n,m,invmtx);
}
int main()
{
	pair<int,int> item;
	int r,m,n,i,t,p,x,y;
	scanf("%d",&r);
	for( t = 0; t < r; t++ )
	{
		scanf("%d%d",&n,&m);
		for( i = 0; i < m; i++ )
		{
			scanf("%d%d%d",&x,&y,&p);
			matrix[x].push_back(make_pair(y,p));
			invmtx[y].push_back(make_pair(x,p));
		}
		printf("%d\n",invitation_cards(n,m));
		for( i = 1; i <= n; i++ )
		{
			matrix[i].clear();
			invmtx[i].clear();
		}
	}
	return 0;
}
