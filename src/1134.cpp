#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>

using namespace std;

#define MAX_NODE 1600

struct node_t
{
	int child,parent,sibling;
}node[MAX_NODE];


int root(int n)
{
	for( int i = 0; i < n; i++ )
	{
		if( node[i].parent < 0 )
			return i;
	}
	return -1;
}

/************dp method,also correct*********************
int table[MAX_NODE][2];
void bfs(int root)
{
	int c = node[root].child;
	table[root][0] = 0;
	table[root][1] = 1;
	
	while( c >= 0 )
	{
		bfs(c);
		c = node[c].sibling;
	}
	for( c = node[root].child; c >= 0; c = node[c].sibling )
	{
		table[root][0] += table[c][1];
		table[root][1] += min(table[c][0],table[c][1]);
	}
}

int dp(int root)
{
	bfs(root);
	return min(table[root][0],table[root][1]);
}
*******************************************/
/********************greed method*************************/
int table[MAX_NODE];
void bfs(int root,int& count)
{
		int p = node[root].parent;
		int c = node[root].child;
		if( c < 0 )//leaf
		{
			if( p >= 0 && table[p] == 0 )
			{
				table[p] = 1;//parent must be
				count += 1;
			}
		}
		else//not leaf, check child;
		{
			for( ;c >=0; c = node[c].sibling )
				bfs(c,count);
			for( c = node[root].child; c >= 0; c = node[c].sibling )
				if( table[c] != 1 )
					break;
			if( c >= 0 )//some 1,some 0,root must 1
			{
				if( table[root] != 1 )
				{
					table[root] = 1;
					count += 1;
				}
			}

		}
}
int dp(int root)
{
	int count = 0;
	memset(table,0,sizeof(table));
	bfs(root,count);
	return count;
}
/*********************************************************/

int main()
{
	int n,i,k;
	int id,child,prev,next;
	while(scanf("%d",&n) != -1)
	{
		memset(node,-1,sizeof(node));
		for( k = 0; k < n; k++ )
		{
			scanf("%d:(%d)",&id,&child);
			if( child > 0 )
			{
				scanf("%d",&prev);
				node[id].child = prev;
				for( i = 1; i < child; i++ )
				{
					scanf("%d",&next);
					node[prev].parent = id;
					node[prev].sibling = next;
					prev = next;
				}
				node[prev].parent = id;
			}
		}
		printf("%d\n",dp(root(n)));
	}
	return 0;
}