#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define LINE 1024
#define ALPHABET_ELN 27

struct node_t
{
	int n;
	node_t* left;
	node_t* right;
};

struct comp_t
{
	bool operator()(const node_t* x, const node_t* y )
	{
		return x->n > y->n;
	}
};

node_t* huffman( node_t** start, node_t** end )
{
	node_t* root;
	node_t* r;
	node_t* s;	
	priority_queue<node_t*,vector<node_t*>,comp_t> Q;
	for( node_t** iter = start; iter != end; iter++ )
		Q.push(*iter);
	root = Q.top();
	Q.pop();
	while( Q.empty() != true )
	{
		s = Q.top();	
		Q.pop();

		r = root;
		root = new node_t();
		root->n = r->n+s->n;
		if( r-> n < s->n )
		{
			root->left = r;
			root->right = s;
		}
		else
		{
			root->left = s;
			root->right = r;
		}
		Q.push(root);
		root = Q.top();
		Q.pop();
	}
	return root;
}

char line[LINE];
int alphabet[ALPHABET_ELN];
node_t* nodes[ALPHABET_ELN];

int get_result( node_t* root,int d )
{
	int ret = 0;
	if( root->left == 0 && root->right == 0 )	
		ret = root->n*d;
	else
	{
		if( root->left != 0 )
			ret += get_result(root->left,d+1);
		if( root->right != 0 )
			ret += get_result(root->right,d+1);
	}
	return ret;
}

void dispose( node_t* root )
{
	if( root->left != 0 )	
		dispose(root->left);
	if( root->right )
		dispose(root->right );
	delete root;	
}


int main()
{
	int i,n,least_bit,max_bit;
	node_t* root;
	while(scanf("%s",line) && strcmp(line,"END") != 0 )	
	{
		memset(alphabet,0,sizeof(alphabet));
		for( i = 0; line[i] != 0; i++ )	
		{
			if( line[i] == '_' )
				alphabet[26] += 1;
			else
				alphabet[line[i]-'A'] += 1;
		}
		for( i = n = 0; i < ALPHABET_ELN; i++ )
		{
			if( alphabet[i] != 0 )
			{
				nodes[n] = new node_t();
				nodes[n]->n = alphabet[i];
				nodes[n]->left = nodes[n]->right = 0;
				n += 1;
			}
		}

		max_bit = 8*strlen(line);

		if( n == 1 )
			least_bit = nodes[0]->n;
		else
		{
			root = huffman(nodes,nodes+n);
			least_bit = get_result(root,0);
			dispose(root);
		}
		printf("%d %d %0.1lf\n",max_bit,least_bit,((double)max_bit)/least_bit);
	}
	return 0;
}
