#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define NODE_SIZE 256

struct node_t
{
	int val;
	struct node_t* left;
	struct node_t* right;
}node_pool[NODE_SIZE];

int travel_nodes[NODE_SIZE];
char node_spec[NODE_SIZE+10];
struct node_t* travel_queue[NODE_SIZE];

char* get_val( char* line,int* val )
{
	int i,tmp;
	for( i = 1,tmp = 0; line[i] != ','; i++ )
		tmp = tmp*10+line[i]-'0';
	*val = tmp;
	return line+i+1;
}
int level_traval( struct node_t* root )
{
	int idx = 0;
	int front = 1;
	int end = 0;
	struct node_t* current;

	travel_queue[0] = root;
	while( end != front )
	{
		current = travel_queue[end++];
		if( (travel_nodes[idx++] = current->val) < 0 )
			return -1;
		if( current->left != NULL )
			travel_queue[front++] = current->left;
		if( current->right != NULL )
			travel_queue[front++] = current->right;
	}
	return idx;
}

int main()
{
	char *p;
	int pool = 0;
	int value,idx,i;
	struct node_t* current;

	struct node_t* root = &node_pool[pool++];
	root->left = root->right = NULL;
	root->val = -1;

	while( scanf("%s",node_spec) != -1 )	
	{
		if( strcmp(node_spec,"()") != 0 )
		{
			p = get_val(node_spec,&value);
			for( current = root; *p != ')'; p++ )
			{
				if( *p == 'L' )
				{
					if( current->left == NULL )
					{
						current->left = &node_pool[pool++];		
						current->left->left = current->left->right = NULL;
						current->left->val = -1;
					}
					current = current->left;
				}
				else
				{
					if( current->right == NULL )
					{
						current->right = &node_pool[pool++];		
						current->right->left = current->right->right = NULL;
						current->right->val = -1;
					}
					current = current->right;
				}
			}
			current->val = current->val < 0 ? value:-1;
		}
		else
		{
			if( (idx = level_traval(root)) < 0 )
				printf("not complete\n");
			else
			{
				printf("%d",travel_nodes[0]);	
				for( i = 1; i < idx; i++ )
					printf(" %d",travel_nodes[i]);
				printf("\n");
			}
			pool = 0;
			root = &node_pool[pool++];
			root->left = root->right = NULL;
			root->val = -1;

		}
	}
	return 0;
}
