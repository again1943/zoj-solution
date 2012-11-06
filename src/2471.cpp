#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>

#define MAX_SIZE 1024
char field[MAX_SIZE][MAX_SIZE];
bool touch[MAX_SIZE][MAX_SIZE];

int next[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

inline bool inside(int x,int y, int n, int m)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}
void fill( int x, int y,int n, int m)
{
	int i,nx,ny;
	std::pair<int,int>item;
	std::queue<std::pair<int,int> >Q;
	touch[item.first][item.second] = true;
	Q.push(std::make_pair(x,y));

	while( Q.empty() != true )
	{
		item = Q.front();
		Q.pop();
		for( i = 0; i < 8; i++ )
		{
			nx = item.first+next[i][0];
			ny = item.second+next[i][1];
			if(inside(nx,ny,n,m) && field[nx][ny] == '#' && touch[nx][ny] != true)
			{
				touch[nx][ny] = true;
				Q.push(std::make_pair(nx,ny));
			}
		}
	}

}
bool check( int x0,int y0, int x1, int y1,int n, int m)
{
	int i;
	if( (inside(x0-1,y0-1,n,m) && field[x0-1][y0-1] == '#') ||
		(inside(x0-1,y1+1,n,m) && field[x0-1][y1+1] == '#') ||
		(inside(x1+1,y0-1,n,m) && field[x1+1][y0-1] == '#') ||
		(inside(x1+1,y1+1,n,m) && field[x1+1][y1+1] == '#'))
		return false;
	if( x0-1 >= 0 )
	{
		for( i = y0; i <= y1; i++ )
			if( field[x0-1][i] == '#' )
				return false;
	}
	if( x1+1 < n )
	{
		for( i = y0; i <= y1; i++ )
			if( field[x1+1][i] == '#' )
				return false;
	}
	if( y0-1 >= 0 )
	{
		for( i = x0; i <= x1; i++ )
			if( field[i][y0-1] == '#' )
				return false;
	}
	if( y1+1 < m )
	{
		for( i = x0; i <= x1; i++ )
			if( field[i][y1+1] == '#' )
				return false;
	}
	return true;
}

inline bool scan(char* line, int d, char c )
{
	int i;
	for( i = 0; i < d; i++ )
		if( line[i] != c )
			return false;
	return true;
}
// find a ship returns 1 else returns 0
bool deep(int x, int y,int n, int m)
{
	int i,d;
	for( i = y; i < m && field[x][i] == '#'; i++ );
	d = i-y;
	for( i = x+1; i < n && scan(field[i]+y,d,'#'); i++);
	fill(x,y,n,m);
	return check(x,y,i-1,y+d-1,n,m);
}

int bfs( int n, int m )
{
	int i,j;
	int ship = 0;
	memset(touch,false,sizeof(touch));
	for( i = 0; i < n; i++ )
		for( j = 0; j < m; j++ )
		{
			if( field[i][j] == '#' && touch[i][j] != true )
			{
				if( deep(i,j,n,m) != true )
					return -1;
				ship += 1;
			}
		}
		return ship;
}


int main()
{
	int n,m,i,r;
	while( scanf("%d%d",&n,&m) != -1 && n != 0 )
	{
		for( i = 0; i < n; i++ )
			scanf("%s",field[i]);
		if( ( r = bfs(n,m)) < 0 )
			printf("Bad placement.\n");
		else
			printf("There are %d ships.\n",r);
	}
	return 0;
}
