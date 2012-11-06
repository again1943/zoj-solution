#include<cstdio>
using namespace std;
#define MAZE_SIZE 64

struct pos_t
{
	int x,y;
	char direct;
};

char maze[MAZE_SIZE][MAZE_SIZE];

inline char rotate_90(const pos_t& p, bool colck_wise )
{
	if( colck_wise == true )
	{
		if( p.direct == 'N' )	
			return 'E';
		if( p.direct == 'E' )
			return 'S';
		if( p.direct == 'S' )
			return 'W';
		else
			return 'N';
	}
	else
	{
		if( p.direct == 'N' )	
			return 'W';
		if( p.direct == 'W' )
			return 'S';
		if( p.direct == 'S' )
			return 'E';
		else
			return 'N';
	}
}

inline bool inside( int x, int y, int row, int col )
{
	return ( x >= 0 && x < row && y >= 0 && y < col );
}

void forward( pos_t& pos,int row, int col )
{
	switch(pos.direct)
	{
		case 'S':
			if( inside(pos.x+1,pos.y,row,col) 
					&& maze[pos.x+1][pos.y] != '*' )	
				pos.x += 1;
			break;
		case 'E':
			if( inside(pos.x,pos.y+1,row,col) 
					&& maze[pos.x][pos.y+1] != '*' )	
				pos.y += 1;
			break;
		case 'N':
			if( inside( pos.x-1,pos.y,row,col) &&
					maze[pos.x-1][pos.y] != '*' )
				pos.x -= 1;
			break;
		case 'W':
			if( inside( pos.x, pos.y-1,row,col)&&
					maze[pos.x][pos.y-1] != '*' )
				pos.y -= 1;
			break;
		default:
			break;
	}
}
int main()
{
	pos_t pos;
	int R,C,i,c,x,y;
	while( scanf("%d%d",&R,&C) != -1 )
	{
		getchar();
		for( i = 0; i < R; i++ )	
			gets(maze[i]);
		scanf("%d%d",&x,&y);
		pos.x = x-1;
		pos.y = y-1;
		pos.direct = 'N';
		while( (c = getchar()) != 'Q' )
		{
			switch( c )	
			{
				case 'R':
					pos.direct = rotate_90(pos,true);
					break;
				case 'L':
					pos.direct = rotate_90(pos,false);
					break;
				case 'F':
					forward(pos,R,C);		
					break;
				default:
					break;
			}
		}
		printf("%d %d %c\n",pos.x+1, pos.y+1,pos.direct);
	}
	return 0;
}
