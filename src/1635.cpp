#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<bitset>
using namespace std;
#define LINE_LEN 512
#define NAME_LEN 12
#define MAX_CHILD 10
#define TREE_DEPTH 12

struct dir_t
{
	bool dir;
	int size,total,n;
	char name[NAME_LEN];	
	dir_t* child[MAX_CHILD];
};
char line[LINE_LEN];

inline void make_node( dir_t* root, char* name, int size,bool dir )
{
	memset(root,0,sizeof(dir_t));	
	root->dir = dir;
	root->size = size;
	strcpy(root->name,name);
}

int eat_node(char* line, int& pos,char* name, int& size,bool& dir )
{
	char s[NAME_LEN];
	int idx = 0;
	while( line[pos] == ' ' )		
		pos += 1;
	if( line[pos] == ')' )
	{
		pos += 1;
		return -1;	
	}
	dir = false;
	if( line[pos] == '*' )	
	{
		dir = true;
		pos += 1;
	}
	while( line[pos] != ' ' )		
		name[idx++] = line[pos++];	
	name[idx] = 0;

	while( line[pos] == ' ' )
		pos += 1;
	idx = 0;

	while( line[pos] != ' ' && line[pos] != ')')
		s[idx++] = line[pos++];
	s[idx] = 0;
	size = atoi(s);
	return 1;	
}
void eat_item( char* line, int& pos,dir_t* parent )
{
	dir_t* iter;	
	int size;
	bool dir;
	char name[NAME_LEN];	
	while( line[pos] != '(' && line[pos] != 0 )
		pos += 1;
	if( line[pos] == 0 )
	{
		pos  = -1;
		return ;
	}
	pos += 1;
	while( eat_node(line,pos,name,size,dir) >= 0 )
	{
		iter = new dir_t;
		make_node(iter,name,size,dir);
		parent->child[parent->n++] = iter;
	}
	if( line[pos] == 0 )
		pos = -1;
}
int cal_size( dir_t* root )
{
	int i;
	root->total = root->size;	
	if( root-> n != 0 )
	{
		for( i = 0; i < root->n; i++ )
			root->total += cal_size(root->child[i]);	
	}
	return root->total;
}

void format_output(dir_t* root, int depth, bitset<TREE_DEPTH>& bit,bool last )
{
	int i;
	if( bit[0] == true )
		printf("|");	
	else
		printf(" ");
	for( i = 1; i < depth; i++ )
		printf("%s",((bit[i] == true )?"       |":"        "));
	printf("_%s%s[%d]\n",(root->dir?"*":""),root->name,root->total);
	if( last == true )
		bit[depth-1] = false;
	if( root->n != 0 )
	{
		bit[depth] = true;
		for( i = 0; i < root->n-1; i++ )
			format_output(root->child[i],depth+1,bit,false);	
		format_output(root->child[i],depth+1,bit,true);	
	}
}
void dispose(dir_t* root )
{
	int i;
	if( root-> n != 0 )	
	{
		for( i = 0; i < root->n; i++ )	
			dispose(root->child[i]);
	}
	delete root;
}
int main()
{
	int size,i;
	int pos;
	queue<dir_t*> Q;
	bitset<TREE_DEPTH>bit;
	dir_t *root,*item,*iter;
	while( scanf("%s%d",line,&size) != -1 )			
	{
		getchar();
		root = new dir_t;
		if( line[0] != '*' )
			make_node(root,line,size,false);	
		else
		{
			pos = -1;
			make_node(root,line+1,size,true);		
			Q.push(root);
			while( Q.empty() != true )
			{
				item = Q.front();
				Q.pop();
				if( pos < 0 )
				{
					gets(line);	
					pos = 0;	
				}
				eat_item(line,pos,item);
				for( i = 0; i < item->n; i++ ) 
				{
					iter = item->child[i];
					if( iter->dir == true )
						Q.push(iter);
				}
			}
			cal_size(root);
			bit[0] = true;
		}
		format_output(root,1,bit,true);
		dispose(root);
	}
}
