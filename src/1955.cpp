#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_LINE 512

unsigned char field[MAX_LINE][MAX_LINE/8];

inline void single( unsigned char* bit, int pos)
{
	bit[pos/8] |= (1<<(pos%8));
}

inline void setbit( int x, int y, int w)
{
	int i,j;
	for( i = 0; i < w; i++ )
		for( j = 0; j < w; j++ )
			single(field[x+i],y+j);
}
void dfs(int x, int y, int w)
{
	switch(getchar())
	{
	case 'Q':
		dfs(x,y,w/2);
		dfs(x,y+w/2,w/2);
		dfs(x+w/2,y,w/2);
		dfs(x+w/2,y+w/2,w/2);
		break;
	case 'B':
		setbit(x,y,w);
		break;
	case 'w': // already 0,do nothing
	default:
		break;
	}
}
inline void parse(int n)
{
	int p = 0;
	memset(field,0,sizeof(field));
	dfs(0,0,n);
}
int main()
{
	int n,i,j;
	while( scanf("%d",&n) != -1 )
	{
		getchar();
		parse(n);
		printf("#define quadtree_width %d\n"
			"#define quadtree_height %d\n"
			"static char quadtree_bits[] = {\n",n,n);
		for( i = 0; i < n; i++ )
		{
			for( j = 0; j < n/8; j++ )
				printf("0x%02x,",field[i][j]);
			printf("\n");
		}
		printf("};\n");
	}
	return 0;
}
