#include<cstdio>
using namespace std;
#define GRID 19

int maze[GRID][GRID];

bool inside( int x, int y, int n )
{
	return (x >= 0 && x < n && y >= 0 && y < n );
}

bool win( int maze[][GRID], int x, int y, int color )
{
	int i,j;
	for( i = 0; i < 5; i++ )	
	{
		if( !inside(x,y+i,GRID) || maze[x][y+i] != color )
			break;
	}
	if( i >= 5 && 
		( !inside(x,y-1,GRID)||maze[x][y-1] != color)&&
		( !inside(x,y+i,GRID)||maze[x][y+i] != color )) //if and only five
		return true;
	for( i = 0; i < 5; i++)
	{
		if( !inside(x+i,y,GRID) || maze[x+i][y] != color )
			break;
	}
	if( i >= 5 &&( !inside(x-1,y,GRID)||maze[x-1][y] != color)&&
		(!inside(x+i,y,GRID) || maze[x+i][y] != color))
		return true;
	for( i = 0; i < 5; i++ )
	{
		if( !inside(x+i,y+i,GRID) || maze[x+i][y+i] != color )
			break;
	}
	if( i >= 5 &&(!inside(x-1,y-1,GRID)||maze[x-1][y-1] != color)&&
		(!inside(x+i,y+i,GRID)||maze[x+i][y+i] != color))
		return true;
	for( i = 0; i < 5; i++ )
	{
		if( !inside(x-i,y+i,GRID) || maze[x-i][y+i] != color )
			break;
	}
	if( i >= 5 && (!inside(x+1,y-1,GRID) || maze[x+1][y-1] != color) &&
		(!inside(x-i,y+i,GRID)||maze[x-i][y+i] != color))
		return true;
	return false;
}
int decide( int maze[][GRID], int& x, int& y )
{
	int i,j;
	int n = GRID;
	for( i = 0; i < n; i++ )	
	for( j = 0; j < n; j++ )
	{
		if( maze[j][i] == 0 )
			continue;
		else if( maze[j][i] == 1 )
		{
			if( win(maze,j,i,1) == true )		
			{
				x = j;
				y = i;
				return 1;
			}
		}
		else
		{
			if( win(maze,j,i,2) == true )
			{
				x = j;
				y = i;
				return 2;
			}
		}
	}
	return 0;
}

int main()
{
	int n,i,j,k,x,y,retval;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < GRID; j++ )	
		for( k = 0; k < GRID; k++ )
			scanf("%d",&maze[j][k]);
		if( (retval = decide(maze,x,y)) != 0 )
			printf("%d\n%d %d\n",retval,x+1,y+1);
		else
			printf("0\n");
	}
	return 0;
}
