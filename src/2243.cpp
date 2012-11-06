#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define STR_LEN 8
#define TEMP_LEN 128
#define NODE_CNT 50002
char total_name[(NODE_CNT+1)*8];
struct node_t
{
	int value;
	char *name;
	bool operator<(const node_t& node ) const
	{
		return strcmp(this->name,node.name) < 0;
	}
}nodes[NODE_CNT];

struct tree_t
{
	int idx,left,right;
}tree[NODE_CNT];

char temp[TEMP_LEN];

void get_content( char* line, node_t& node,int n )
{
	int i = 0;		
	node.name = total_name+n*8;
	for( i = 0; line[i] != '/' ; i++ )
		node.name[i] = line[i];
	node.name[i] = 0;
	node.value = atoi(line+i+1);
}
void print( int root)
{
	printf("(");
	if( tree[root].left != -1 )	
		print(tree[root].left);	
	printf("%s/%d",nodes[root].name,nodes[root].value);
	if( tree[root].right != -1 )
		print(tree[root].right);
	printf(")");
}

int treap( int n )
{
	int i,y;	
	int root = 0;
	tree[0].idx = tree[0].left = tree[0].right = -1;
	for( i = 1; i < n; i++ )
	{
		y = i-1;		
		while( nodes[i].value > nodes[y].value  && y >= 0 )
			y = tree[y].idx;
		tree[i].idx = y;
		tree[i].right = -1;
		if( y < 0 )
		{
			tree[i].left = root;
			tree[root].idx = i;
			root = i;
		}
		else
		{
			tree[i].left = tree[y].right;	
			if( tree[y].right != -1 )	
				tree[tree[y].right].idx = i;	
			tree[y].right = i;
		}
	}
	return root;
}
int main()
{
	int i,n;
	int root;
	while(scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )	
		{
			scanf("%s",temp);
			get_content(temp,nodes[i],i);
		}
		sort(nodes,nodes+n);
		root = treap(n);
		print(root);
		printf("\n");
	}
	return 0;
}
