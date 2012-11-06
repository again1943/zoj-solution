#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

#define MAXN 500004
struct node_t
{
	int parent;//parent 
	int silbing;//sibling
	int first;//first child
	int last;//last child
	int value[2];//total value of tree,
				//value[0]: max value when this node have no grants and give grant to a child
				//value[1]: max value then this node have a grant and give no grant to any child
	int gchild;//if we have no grant, which child we give our only grant?
}nodes[MAXN];

void dp(int r)
{
	int child,value,maxval,idx,tmp;
	if( nodes[r].first < 0 )//leaf
	{
		nodes[r].value[0] = 0;
		nodes[r].value[1] = 1000;
	}
	else
	{
		for( child = nodes[r].first; child > 0; child = nodes[child].silbing )
			dp(child);
		for( child = nodes[r].first,value = 0; child > 0; child = nodes[child].silbing )
			value += nodes[child].value[0];
		nodes[r].value[1] = value;
		if( nodes[r].parent > 0 )//have parent
			nodes[r].value[1] += 1000;
		for( child = nodes[r].first,maxval = -1; child > 0; child = nodes[child].silbing )
		{
			tmp = value-nodes[child].value[0]+nodes[child].value[1];
			if( tmp > maxval )
			{
				maxval = tmp;
				idx = child;
			}
		}
		nodes[r].value[0] = maxval;
		nodes[r].gchild = idx;
	}
}
void output(int r,int which,vector<int>&vec)
{
	int child,gchild;
	if( which == 1 )
	{
		for(child = nodes[r].first; child > 0; child = nodes[child].silbing )
			if( nodes[child].first > 0 )
				output(child,0,vec);
	}
	else
	{
		gchild = nodes[r].gchild;
		vec.push_back(gchild);
		for( child = nodes[r].first; child > 0; child = nodes[child].silbing )
			if( nodes[child].first > 0 )
				output(child,(child==gchild?1:0),vec);
	}
}
int main()
{
	int m,k,i,n,item,last,value;
	vector<int>out;
	//freopen("data.txt","r",stdin);
	scanf("%d",&m);
	for( k = 0; k < m; k++ )
	{
		scanf("%d",&n);
		out.clear();
		memset(nodes,-1,sizeof(node_t)*(n+2));
		for ( i = 2; i <= n; i++ )
		{
			scanf("%d",&item);
			nodes[i].parent = item;
			if( nodes[item].first < 0 )
			{
				nodes[item].first = i;
				nodes[item].last = i;
			}
			else
			{
				last = nodes[item].last;
				nodes[item].last = i;
				nodes[last].silbing = i;
			}
		}
		dp(1);
		if( nodes[1].value[0] > nodes[1].value[1] )
		{
			value = nodes[1].value[0];
			output(1,0,out);
		}
		else
		{
			value = nodes[1].value[1];
			output(1,1,out);
		}
		sort(out.begin(),out.end());
		if( k != 0 )
			printf("\n");
		printf("%d\n",value);
		printf("%d",out[0]);
		for( size_t i = 1; i < out.size(); i++ )
			printf(" %d",out[i]);
		printf("\n");
	}
	return 0;
}