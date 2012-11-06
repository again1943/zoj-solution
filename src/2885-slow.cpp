#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX_NODE 10004
char line[MAX_NODE];

struct order_t
{
	vector<order_t*>child;	
};

void dispose_order( order_t* root )
{
	int i,size;
	if( root != 0 )	
	{
		size = root->child.size();
		for( i = 0; i < size; i++ )		
			dispose_order(root->child[i]);
		delete root;
	}
}

struct binary_t
{
	binary_t *left,*right;	
};

int dispose_binary( binary_t* root )
{
	int left = 0;
	int right = 0;
	if( root != 0 )
	{
		if( root->left )
			left = dispose_binary(root->left)+1;
		if( root->right)
			right = dispose_binary(root->right)+1;
		delete root;
	}
	return max(left,right);
}

binary_t* binary(order_t* order_root)
{
	int i,size;
	binary_t* ctl;
	binary_t* root = new binary_t;					
	root->left = root->right = 0;

	if( order_root->child.size() != 0 )
	{
		size = order_root->child.size();
		root->left = binary(order_root->child[0]);
		for( i = 1,ctl = root->left; i < size; i++ )
		{
			ctl->right = binary(order_root->child[i]);
			ctl = ctl->right;
		}
	}
	return root;
}
order_t* order( char* line,int& pos,int& horder,int& maxval )
{
	order_t* root = new order_t;				
	while( line[pos] != 0 )
	{
		if( line[pos] == 'u' )	
		{
			horder -= 1;
			pos += 1;
			break;
		}
		else
		{
			pos += 1;
			horder += 1;
			maxval = max(maxval,horder);
			root->child.push_back(order(line,pos,horder,maxval));
		}
	}
	return root;
}

void order_tree( char* line, int& horder, int& hbinary )
{
	int h = 0;
	int p = 0;
	horder = hbinary = 0;
	order_t* order_root = order(line,p,h,horder);
	binary_t* binary_root = binary(order_root);
	hbinary = dispose_binary(binary_root);
	dispose_order(order_root);
}
int main()
{
	int t = 0;
	int horder,hbinary;
	while( scanf("%s",line) && strcmp(line,"#") != 0 )
	{
		order_tree(line,horder,hbinary);		
		printf("Tree %d: %d => %d\n",++t,horder,hbinary);
	}
	return 0;
}
