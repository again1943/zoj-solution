#include <map>
#include <stack>
#include <string>
#include <cstdio>
#include <cstring>
#include <utility>
#include <iostream>
#include <algorithm>

#define MAX_NODE 30002
using namespace std;

map<string,int>MAP;
struct node_t
{
	int p,d;
}node[MAX_NODE];

bool parent(char* base,char* drived)
{
	int x = MAP[base];
	int y = MAP[drived];

	int dx = node[x].d;
	int dy = node[y].d;
	if( dx == 0 )
		return true;
	if( dy < dx )
		return false;
	while( dy > dx )
	{
		y = node[y].p;
		dy -= 1;
	}
	return (x == y);
}
void link(int n)
{
	int i,x,t;
	stack<int> S;
	for( i = 0; i < n; i++ )
	{
		if( node[i].d >= 0 )
			continue;
		S.push(i);
		x = node[i].p;
		while( node[x].d < 0 )
		{
			S.push(x);
			x = node[x].p;
		}
		while( S.empty() != true )
		{
			t = S.top();
			S.pop();
			node[t].d = node[x].d+1;
			x = t;
		}
	}
}
int main()
{
	int t = 0;
	int next,n,query,i,x,y;
	char drived[256],base[256],root[256];
	map<string,int>::iterator item;

	while(scanf("%s%d",root,&n) != -1)
	{	
		next = 0;
		node[0].p = -1;
		node[0].d = 0;
		MAP.insert(make_pair(root,next++));
		for( i = 0; i < n; i++ )
		{
			//cin >> drived >> base;
			scanf("%s%s",drived,base);
			if( (item = MAP.find(base)) == MAP.end())
			{
				y = next++;
				node[y].d = -1;
				MAP.insert(make_pair(base,y));
			}
			else
				y = item->second;
			if( (item = MAP.find(drived)) == MAP.end())
			{
				x = next++;
				node[x].d = -1;
				MAP.insert(make_pair(drived,x));
			}
			else
				x = item->second;
			node[x].p = y;
			if( node[y].d >= 0 )
				node[x].d = node[y].d+1;
		}
		link(n);
		//cin >> query;
		scanf("%d",&query);
		if( t != 0 )
			//cout << '\n';
			printf("\n");
		//cout << "Project " << ++t << '\n';
		printf("Project %d\n",++t);
		for( i = 0; i < query; i++ )
		{
			//cin >> drived >> base;
			scanf("%s%s",drived,base);
			printf("%s\n",(parent(base,drived)?"Yes":"No"));
		}
		MAP.clear();
	}
	return 0;

}
