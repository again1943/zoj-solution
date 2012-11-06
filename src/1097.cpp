#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;

#define SIZE 54
#define LINE_LEN 256

int tree_map[SIZE][SIZE];
char line[LINE_LEN];
int output[SIZE];
int max_elem;

void do_line( char* line )
{
	int i,j;
	for( i = 1,j = 1; line[j] != '\0'; j++ )
	{
		if( line[j] != ' ' )
			line[i++] = line[j];	
	}
	line[i] = '\0';
}

int to_tree( int& pos )
{

	int root = 0;
	int child;
	while( line[pos] != '(' )
		pos++;
	pos += 1;
	while( line[pos] >= '0' && line[pos] <= '9' )
	{
		root = root*10+line[pos]-'0';
//		tree_map[root][0] = 0;
		max_elem = max_elem > root ? max_elem:root;
		pos++;
	}
	if( line[pos] == ')' )
	{
		pos++;
		return root;
	}
	else
	{
		while( line[pos] != ')' )	
		{
			child = to_tree(pos);	
//			tree_map[root][0]++;
//			tree_map[child][0]++;
			tree_map[root][child] = tree_map[child][root] = 1;
		}
		pos++;
		return root;
	}
}

int main()
{
	int idx;
	int pos;
	int elem;
	priority_queue<int,vector<int>, greater<int> > queue;
	while( gets(line) != NULL )	
	{
		pos = 0;
		max_elem = -1;
		memset(tree_map,0,sizeof(tree_map));
		do_line(line);
		to_tree(pos);

		if( max_elem == 1 )
		{
			printf("\n");
			continue;	
		}
		for(int i = 1; i <= max_elem; i++ )
		{
			for( int j = 1; j <= max_elem; j++ )
				tree_map[i][0] += tree_map[i][j];
			
			if( tree_map[i][0] == 1 )
				queue.push(i);
		}

		idx = 0;
		while( queue.empty() != true )
		{
			elem = queue.top();	
			queue.pop();
			if(  elem == max_elem )
				break;
			for( int i = 1; i <= max_elem; i++ )
			{
				if( tree_map[elem][i] == 1 )
				{
					tree_map[i][elem] = tree_map[elem][i] = -1;
					tree_map[elem][0] = 0;
					if( --tree_map[i][0] == 1 )
						queue.push(i);
					output[idx++] = i;
					break;
				}
			}
		}
		
		printf("%d",output[0]);
		for( int i = 1; i < idx; i++ )
			printf(" %d",output[i]);
		printf("\n");
	}
	return 0;
}
