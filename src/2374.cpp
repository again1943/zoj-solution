#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<map>
#include<utility>
using namespace std;
#define NODE_CNT 10001
bool reference[NODE_CNT];
struct node_t
{
	int v;	//value
	int n;	// child count
	int* child; // the index in nodes of the children
}nodes[NODE_CNT];

// the children may modify v of parent,so we need parent as argument
int tree_dp( int root,int parent )
{
	int i;
	int moves = 0;		
	for( i = 0; i < nodes[root].n; i++ )
		moves += tree_dp(nodes[root].child[i],root);
		//delete[] nodes[root].child;
	if( parent >= 0 )
	{
		nodes[parent].v += nodes[root].v-1;	
		moves += abs(nodes[root].v-1);
	}
	if( nodes[root].n != 0 )
		delete[] nodes[root].child;
	return moves;
}
int main()
{
	int n,v,c,idx,i,j,count;
	int root,item;
	map<int,int>M;
	map<int,int>::iterator iter;
	while( scanf("%d",&n) && n != 0 )	
	{
		//memset(nodes,0,sizeof(nodes));
		memset(reference,0,sizeof(reference));
		for( i = count = 0,root = -1; i < n; i++ )
		{
			scanf("%d%d%d",&idx,&v,&c);
			if((iter = M.find(idx)) != M.end())
				item = iter->second;	
			else
			{
				item = count++;
				M.insert(make_pair(idx,item));
			}
			nodes[item].v = v;
			nodes[item].n = c;
			if( c != 0 )
			{	
				nodes[item].child = new int[c];
				for( j = 0; j < c; j++ )
				{
					scanf("%d",&idx);
					if( (iter = M.find(idx)) != M.end())	
					{
						nodes[item].child[j] = iter->second;	
						reference[iter->second] = true;
					}
					else
					{
						reference[count] = true;	
						nodes[item].child[j] = count;
						M.insert(make_pair(idx,count++));
					}
				}
			}
		}
		for( i = 0; i < count; i++ )
		{
			if( reference[i] != true )
			{
				root = i;
				break;
			}
		}
		printf("%d\n",tree_dp(root,-1));
		M.clear();
	}
	return 0;
}
