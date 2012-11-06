#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAX_TREE 65535
#define MAX_LINE 10004
#define NUM_LEN 10

char line[MAX_LINE][12];
char* lineptr[MAX_LINE];
struct comp_t
{
	bool operator()(const char* x, const char* y )
	{
		return strcmp(x,y) > 0;	
	}
};

struct tree_t
{
	tree_t* child[NUM_LEN];	
}tree[MAX_TREE];

int pool;
tree_t* root;	

/*
bool intree( tree_t* root,char* line,int idx )
{
	int c = line[idx]-'0';
	if( line[idx+1] != 0 )	
	{
		if( !root->child[c] )
		{
			root->child[c] = &tree[pool++];
			memset(root->child[c],0,sizeof(tree_t));
		}
		return intree(root->child[c],line,idx+1);
	}
	else
	{
		if( root->child[c] != 0 )	
			return false;
		else
		{
			root->child[c] = &tree[pool++];		
			memset(root->child[c],0,sizeof(tree_t));
			return true;
		}
	}
}*/
bool intree( tree_t* root, char* line )
{
	int i,c;	
	tree_t* item = root;
	for( i = 0; line[i+1] != 0; i++ )
	{
		c = line[i] - '0';
		if( !item->child[c] )
		{
			item->child[c] = &tree[pool++];	
			memset(item->child[c],0,sizeof(tree_t));
		}
		item = item->child[c];
	}
	c = line[i]-'0';
	if( item->child[c] != 0 )
		return false;
	else
	{
		item->child[c] = &tree[pool++];	
		memset(item->child[c],0,sizeof(tree_t));
		return true;
	}
}
int main()
{
	bool yes;
	int test_case,n,i,k;	
	scanf("%d",&test_case);
	for( k = 0; k < test_case; k++ )
	{
		scanf("%d",&n);
		yes = true;
		pool = 0;
		root = &tree[pool++];
		memset(root,0,sizeof(tree_t));

		for( i = 0; i < n; i++ )
		{
			scanf("%s",line[i]);
			lineptr[i] = line[i];
		}
		sort(lineptr,lineptr+n,comp_t());
		for( i = 0; i < n; i++ )
		{
			if( yes != false ) 
				yes = intree(root,lineptr[i]);
		}
		printf("%s\n",(yes?"YES":"NO"));
	}
	return 0;	
}
