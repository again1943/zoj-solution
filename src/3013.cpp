#include <cstring>
#include <cstdio>
#include <utility>
#define INF 100000
#define MAX_NODE 50000
#define MAX_LINE 4100
struct word_t
{
	bool word;
	int child[26];
}node[MAX_NODE];

int NEXT;
char line[MAX_LINE];
int stack[MAX_LINE];
int table[MAX_LINE];
int depart[MAX_LINE];
bool match[MAX_LINE];

void combine(int size)
{
	int k;
	int c = depart[size];
	//int i = size;
	while( 1 )
	{
		if( match[c] == true )
			c = depart[c];
		else
		{
			k = c;
			c = depart[c];
			while( match[c] != true )
				c = depart[c];
			depart[k] = c;
		}
		if( c <= 0 )
			break;
	}

}
void print(int n)
{
	int c,i;
	c = depart[n];
	if( c > 0 )
	{
		print(c);
		printf("#");
	}
	for( i = c+1; i <= n; i++ )
		printf("%c",line[i]);
}

int search(int i,int* stack)
{
	int p,n;
	for( n = p = 0; line[i] != 0;i++  )
	{
		if( (p = node[p].child[line[i]-'a']) < 0 )
			break;
		if( node[p].word == true )
			stack[n++] = i;
	}
	return n;
}
void dp(char* line)
{
	int i,j,n,c;
	int size = strlen(line+1);
	memset(depart,-1,sizeof(depart));
	memset(match,true,sizeof(match));
	for( i = 1; i <= size; i++ )
		table[i] = INF;
	table[0] = 0;
	for( i = 0; i < size; i++ )
	{
		if( table[i+1] > table[i]+1 )
		{
			table[i+1] = table[i]+1;
			depart[i+1] = i;
			match[i+1] = false;
		}
		n = search(i+1,stack);
		for( j = 0; j < n; j++ )
		{
			c = stack[j];
			if( table[c] > table[i] )
			{
				table[c] = table[i];
				depart[c] = i;
			}
		}
	}
	printf("%d\n",table[size]);
	combine(size);
	print(size);
	printf("\n");
}


void insert(char* word)
{
	int i,root,c,p;
	for( i = root = 0; word[i] != 0; i++ )
	{
		p = root;
		if( (root = node[root].child[word[i]-'a']) < 0 )
		{
			c = ++NEXT;
			node[c].word = false;
			memset(node[c].child,-1,sizeof(node[c].child));
			node[p].child[word[i]-'a'] = c;
			root = c;
		}
	}
	node[root].word = true;
}
int main()
{
	int n,m,i;
	char word[16];
	//freopen("3013.txt","r",stdin);
	while(scanf("%d%d",&n,&m) != -1)
	{
		NEXT = 0;
		node[0].word = false;
		memset(node[0].child,-1,sizeof(node[0].child));
		for( i = 0; i < n; i++ )
		{
			scanf("%s",word);
			insert(word);
		}
		for( i = 0; i < m; i++ )
		{
			scanf("%s",line+1);
			dp(line);
		}
	}
	return 0;
}