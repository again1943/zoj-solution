/*
 * =====================================================================================
 *
 *       Filename:  1862.cpp
 *
 *    Description:  solution to zoj 1862
 *
 *        Version:  1.0
 *        Created:  2007年05月17日 14时02分29秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#define MINE_SIZE 12

struct pos_t
{
	bool has_mine;
	bool covered;
};

pos_t map[MINE_SIZE][MINE_SIZE];

bool trigger_mine(int n)
{
	for( int i = 1;i <= n; i++ )	
	for( int j = 1;j <= n; j++ )
	{
		if( map[i][j].covered == true && map[i][j].has_mine == true )
			return true;
	}
	return false; 
}

char get_pos(int x, int y,bool fail)
{
	int count = 0;	
	if( fail == false )
	{
		if( map[x][y].covered == false )
			return '.';
		for( int i = x-1; i <= x+1; i++ )		
		for( int j = y-1; j <= y+1; j++ )
		{
			if( map[i][j].has_mine == true )
				count++;
		}
	}
	else
	{
		if( map[x][y].covered == false )
			return map[x][y].has_mine == true?'*':'.';
		if( map[x][y].has_mine == true )
			return '*';
		for( int i = x-1; i <= x+1; i++ )		
		for( int j = y-1; j <= y+1; j++ )
		{
			if( map[i][j].has_mine == true )
				count++;
		}

	}
	return count+'0';
}
int main()
{
	int n;
	int t = 0;
	char c;
	while( std::scanf("%d",&n) != -1 )
	{
		if(t++)
			std::putchar('\n');
		getchar();
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= n; j++ )
			{
				if( (c = getchar()) == '.' )
					map[i][j].has_mine = false;
				else
					map[i][j].has_mine = true;
			}
			std::getchar();
		}
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= n; j++ )
			{
				if( (c = std::getchar()) == '.' )
					map[i][j].covered = false;
				else
					map[i][j].covered = true;
			}
			std::getchar();
		}
		for( int i = 0; i <= n+1; i++ )
		{
			map[n+1][i].has_mine = map[0][i].has_mine = false;	
			map[i][0].has_mine = map[i][n+1].has_mine = false;
		}
#ifdef DEBUG
		std::printf("mine:\n");
		for( int i = 0; i <= n+1; i++ )
		{
			for( int j = 0; j <= n+1; j++ )
				std::putchar((map[i][j].has_mine==true)?'1':'0');
			std::putchar('\n');
		}
		std::printf("covered:\n");
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= n; j++ )
				std::putchar((map[i][j].covered==true)?'1':'0');
			std::putchar('\n');
		}


#endif
		bool fail = trigger_mine(n);
		for( int i = 1; i <= n; i++ )
		{
			for( int j = 1; j <= n; j++ )
				std::putchar(get_pos(i,j,fail));
			putchar('\n');
		}

	}
	return 0;
}
