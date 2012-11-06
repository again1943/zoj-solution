#include<cstdio>
#include<utility>
#include<stack>
#define SIZE 102

using namespace std;

int map[102][102];
void init_map()
{
	for( int i = 0; i < SIZE; i++ )
		map[0][i] = -1;
	for( int i = 1; i < SIZE; i++ )
		map[i][0] = -1;
}
void set_map( int row, int col )
{
	for( int i = 1; i <= row; i++ )
		map[i][col+1] = -1;
	for( int i = 1; i<=col; i++ )
		map[row+1][i] = -1;
}
void trace( int row, int col )
{
	pair<int,int> pos;
	stack< pair<int,int> >map_stack;
	map_stack.push( make_pair(row,col) );
	while( !map_stack.empty() )
	{
		pos = map_stack.top();
		map_stack.pop();
		map[pos.first][pos.second] = -1;
		if( map[pos.first-1][pos.second] == 1 )
			map_stack.push( make_pair( pos.first-1,pos.second ));
		if( map[pos.first+1][pos.second] == 1 )
			map_stack.push( make_pair( pos.first+1,pos.second ));
		if( map[pos.first][pos.second-1] == 1 )
			map_stack.push( make_pair( pos.first,pos.second-1 ));
		if( map[pos.first][pos.second+1] == 1 )
			map_stack.push( make_pair( pos.first,pos.second+1 ));
		if( map[pos.first+1][pos.second+1]== 1)
			map_stack.push( make_pair( pos.first+1,pos.second+1));
		if( map[pos.first-1][pos.second-1] == 1 )
			map_stack.push( make_pair( pos.first-1,pos.second-1));
		if( map[pos.first-1][pos.second+1] == 1)
			map_stack.push( make_pair( pos.first-1,pos.second+1));
		if( map[pos.first+1][pos.second-1] == 1 )
			map_stack.push( make_pair( pos.first+1,pos.second-1));
	}
}
int main()
{
	int deposit;
	int row,col;
	char line[SIZE];
	init_map();
	scanf("%d%d",&row,&col);
	while( row != 0 )
	{
		deposit = 0;
		set_map( row,col );
		for( int i = 1; i <= row; i++ )
		{
			int index = 1;
			scanf("%s",line );
			for( char *p = line; *p != '\0';p++ )
				map[i][index++] = (*p == '@') ? 1:-1;
		}

		for( int i = 1; i <= row; i++ )
		{
			for( int j = 1; j <= col; j++ )
			{
				if( map[i][j] == 1 )
				{
					deposit++;
					trace( i,j );
				}
			}
		}
		printf( "%d\n",deposit );
		scanf( "%d%d",&row,&col );
	}
}


