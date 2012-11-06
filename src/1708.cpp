#include<cstdio>
#include<utility>

#define MAX_SIZE 10
using namespace std;

pair <int,int >status[MAX_SIZE][MAX_SIZE];
char instruction[MAX_SIZE][MAX_SIZE];
void init_status()
{
	for( int i = 0; i < MAX_SIZE; i++ )
	for( int j = 0; j < MAX_SIZE; j++ )
	{
		status[i][j].first = 0;
		status[i][j].second = 0;
	}
}
int stop( int pos_x,int pos_y, int row, int col)
{
	if( ( pos_x < 0 || pos_x >= row ) || 
			(pos_y < 0 || pos_y >= col ) )
		return -1;
	else if( status[pos_x][pos_y].second > 0 )
		return 0;
	else
		return 1;
}
void get_result( int row, int col, int start, pair<int,int>&result )
{
	int i = 0;
	int j = start-1;
	int step = 0;
	int temp;
	char c;
	init_status();

	temp = stop(i,j,row,col);
	while( temp > 0 )
	{
		status[i][j].first = step++;
		status[i][j].second = 1;
		c = instruction[i][j]; 
		if( c == 'S' )
			i++;
		else if( c == 'N' )
			i--;
		else if( c == 'W' )
			j--;
		else
			j++;
		temp = stop(i,j,row,col);
	}
	if( temp == -1 )
	{
		result.first = step;
		result.second = -1;
	}
	else
	{
		result.first = status[i][j].first;
		result.second = step-status[i][j].first; 

	}
}
int main()
{
	int row,col,start;
	pair<int,int>result;
	scanf("%d%d%d",&row,&col,&start);
	while( row != 0 )
	{
		for( int i = 0; i < row; i++ )
			scanf("%s",instruction[i]);
		get_result(row,col,start,result);
		if( result.second == -1 )
			printf("%d step(s) to exit\n",result.first);
		else
			printf("%d step(s) before a loop of %d step(s)\n",
					result.first,result.second);
		scanf("%d%d%d",&row,&col,&start);
	}

	return 0;
}

