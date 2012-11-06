#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FIELD_SIZE 7
char line[FIELD_SIZE];
bool field[FIELD_SIZE][FIELD_SIZE];
int direct[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
bool inside( int x,int y,int n,int m )
{
	return ( x >= 0 && x < n && y >= 0 && y < m );
}
bool dfs( int x, int y,int cover, int n, int m,int space )
{
	int i,tx,ty;
	if( cover + 1 == space )		
		return true;
	else
	{
		field[x][y] = false;	
		for( i = 0; i < 4; i++ )
		{
			tx = x + direct[i][0];
			ty = y + direct[i][1];
			if( inside(tx,ty,n,m) && field[tx][ty] && dfs(tx,ty,cover+1,n,m,space))
				return true;
		}
		field[x][y] = true;
		return false;
	}
}
int main()
{
	int n,m,i,j,space;
	while( scanf("%d%d",&n,&m) && n != 0 )
	{
		space = 0;
		for( i = 0; i < n; i++ )	
		{
			scanf("%s",line);
			for( j = 0; j < m; j++ )
			{
				if( line[j] == '.')	
				{
					field[i][j] = true;	
					space++;
				}
				else
					field[i][j] = false;
			}
		}
		printf("%s\n",dfs(0,0,0,n,m,space)?"YES":"NO");	
	}
	return 0;
}
