#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAXN 16

int rowmark[MAXN][MAXN];
int colmark[MAXN][MAXN];
int submark[MAXN][MAXN];

char table[MAXN][MAXN];

inline int postocell(int x, int y)
{
	return (x/3)*3+(y/3);
}
bool sudoku(int x,int y)
{
	int i;
	int a = x+(y+1)/9;
	int b = (y+1)%9;
	int z = postocell(x,y);
	int c = table[x][y]-'0';
	if( c != 0 )		
	{
		if( (x == 8 && y == 8) || sudoku(a,b) == true )
			return true;
	}
	else
	{
		for( i = 1; i <= 9; i++ )
		{
			c = i;
			if( rowmark[x][c] == 0 && colmark[y][c] == 0 && submark[z][c] == 0 )
			{
				rowmark[x][c] = colmark[y][c] = submark[z][c] = 1;
				table[x][y] = c+'0';
				if( (x == 8 && y == 8) || sudoku(a,b) == true )
					return true;
				rowmark[x][c] = colmark[y][c] = submark[z][c] = 0;
				table[x][y] = '0';
			}
		}
	}
	return false;
}
int main()
{
	int n,i,j,x,y,z,c;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		memset(table,0,sizeof(table));
		for( j = 0; j < 9; j++ )
			scanf("%s",table[j]);
		memset(rowmark,0,sizeof(rowmark));
		memset(colmark,0,sizeof(colmark));
		memset(submark,0,sizeof(submark));
		for( x = 0; x < 9; x++ )
			for( y = 0; y < 9; y++ )
			{
				if( table[x][y] == '0' )
					continue;
				c = table[x][y]-'0';	
				if( c != 0 )
				{
					z = postocell(x,y);
					rowmark[x][c] = 1;
					colmark[y][c] = 1;
					submark[z][c] = 1;
				}
			}
			sudoku(0,0);
			for( j = 0; j < 9; j++ )
				printf("%s\n",table[j]);
	}
	return 0;
}
