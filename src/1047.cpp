#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX_CNT 24
char image[MAX_CNT][MAX_CNT];
bool cover[MAX_CNT][MAX_CNT];
bool inside( int x, int y, int R, int C )
{
	return ( x >= 0 && x < R && y >= 0 && y < C );
}
int direct[][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

int dfs( int R,int C, int x, int y )
{
	int r,c,i;
	int perimeter = 0;
	cover[x][y] = true;
	for( i = 0; i < 4; i++ )	
	{
		r = x+direct[i][0];	
		c = y+direct[i][1];
		if( inside(r,c,R,C) && !cover[r][c] )
		{
			if( image[r][c] == '.' )
				perimeter += 1;
			else
				perimeter += dfs(R,C,r,c);
		}
	}
	for( i = 4; i < 8; i++ )
	{
		r = x+direct[i][0];	
		c = y+direct[i][1];
		if( inside(r,c,R,C) && !cover[r][c] && image[r][c] == 'X')
			perimeter += dfs(R,C,r,c);	
	}
	return perimeter;	
}
int main()
{
	int R,C,x,y,i;
	while( scanf("%d%d%d%d",&R,&C,&x,&y) && R != 0 )
	{
		for( i = 1; i <= R; i++ )
			scanf("%s",image[i]+1);
		memset(cover,0,sizeof(cover));
		for( i = 0; i < C+2; i++ )	
			image[0][i] = image[R+1][i] = '.';	
		for( i = 0; i < R+2; i++ )
			image[i][0] = image[i][C+1] = '.';
		printf("%d\n",dfs(R+2,C+2,x,y));
	}
	return 0;
}
