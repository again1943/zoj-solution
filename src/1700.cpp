#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define TREE_SIZE 26
#define NO_CHILD -1
using namespace std;

struct tree_t
{
	int left, right;
	tree_t()
	{
		left = right = NO_CHILD;
	}
};

int root;
tree_t tree[TREE_SIZE];
char IN[TREE_SIZE][TREE_SIZE];

void insert(int root, int elem)
{
	if( elem != root )
	{
		if( elem > root )
		{
			if( tree[root].right != NO_CHILD )
				insert(tree[root].right,elem);
			else
			{
				tree[root].right = elem;	
				tree[elem].left = tree[elem].right = NO_CHILD;
			}
		}
		else
		{
			if( tree[root].left != NO_CHILD )	
				insert(tree[root].left,elem);
			else
			{
				tree[root].left = elem;
				tree[elem].left = tree[elem].right = NO_CHILD;
			}
		}
	}
}
void pre_order( int root )
{
	printf("%c",root+'A');
	if( tree[root].left != NO_CHILD )	
		pre_order(tree[root].left);
	if( tree[root].right != NO_CHILD )
		pre_order(tree[root].right);
}

void do_all( int idx )
{
	int x = idx-1;	
	root = IN[x][0]-'A';
	for( int i = x-1; i >= 0; i-- )
		for(int j = 0; IN[i][j] != '\0'; j++ )	
			insert(root,IN[i][j]-'A');
	pre_order(root);
	printf("\n");
}

int main()
{
	int idx = 0;
	char temp[TREE_SIZE];	
	while( scanf("%s",temp) && strcmp(temp,"$") != 0 )
	{
		if( strcmp(temp,"*") != 0 )
			strcpy(IN[idx++],temp);
		else
		{
			do_all(idx);	
			idx = 0;
			fill(tree,tree+TREE_SIZE,tree_t());
		}
	}
	do_all(idx);
	return 0;
}
