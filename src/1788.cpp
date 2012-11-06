#include<queue>
#include<cstdio>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;
#define IMAGE_SIZE 512
int bitmap[IMAGE_SIZE][IMAGE_SIZE];
char HEX[] = "0123456789ABCDEF";
struct node_t
{
	unsigned char val;
	node_t* child[4];
	node_t(unsigned char v)
	{
		val = v;	
		child[0] = child[1] = child[2] = child[3] = 0;
	}
}*root;

node_t* build_tree(int srow,int erow,int scol,int ecol)
{
	int i;
	int midr = (srow+erow)/2;
	int midc = (scol+ecol)/2;
	node_t* ret = new node_t((unsigned char)bitmap[srow][scol]);
	if( erow - srow > 1 )
	{
		ret->child[0] = build_tree(srow,midr,scol,midc);	
		ret->child[1] = build_tree(srow,midr,midc,ecol);
		ret->child[2] = build_tree(midr,erow,scol,midc);
		ret->child[3] = build_tree(midr,erow,midc,ecol);
		if( (ret->child[0]->val == ret->child[1]->val)&&
			(ret->child[1]->val == ret->child[2]->val)&&
			(ret->child[2]->val == ret->child[3]->val))
		{
			for( i = 0; i < 4; i++ )	
			{
				delete ret->child[i];
				ret->child[i] = 0;
			}
		}
		else
			ret->val = 2;	
	}
	return ret;
}

void bit_tree(node_t* root, string& bits )
{
	int i;
	node_t* top;
	queue<node_t*> Q;			
	Q.push(root);		
	while( Q.empty() != true )
	{
		top = Q.front();	
		Q.pop();
		if( top->val  == 2 )	
			bits += "1";	
		else if( top->val == 1 )
			bits += "01";
		else
			bits += "00";
		for( i = 0; i < 4; i++ )
			if( top->child[i] != 0 )
				Q.push(top->child[i]);
		delete top;
	}
}
unsigned int sint( string& s, int start,int end )
{
	int i;
	unsigned int ret = 0;	
	unsigned int mask = 1;
	for( i = start; i < end; i++ )
	{
		if( s[i] == '1' )	
			ret |= mask;	
		mask <<= 1;
	}
	return ret;
}
void print( string& s )
{
	int i;
	int size = s.size();
	reverse(s.begin(),s.end());
	if( size % 4 != 0 )
		printf("%c",HEX[sint(s,(size/4)*4,size)]);
	for( i = size/4-1; i >= 0; i-- )
		printf("%c",HEX[sint(s,i*4,(i+1)*4)]);
	printf("\n");
}
int main()
{
	int n,i,j,t,k;
	string ret;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d",&n);
		for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
			scanf("%d",&bitmap[i][j]);
		root = build_tree(0,n,0,n);
		bit_tree(root,ret);
		print(ret);
		ret.clear();
	}
	return 0;
}
