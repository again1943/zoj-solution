#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define RECT_SIZE 201
char matrix[RECT_SIZE][RECT_SIZE];
void color_matrix(char matrix[][RECT_SIZE],int col, int ax,int ay, int bx, int by)
{
	int i;
	int srow,erow,scol,ecol;
	char color = (char)col;	
	srow = min(ay+100,by+100);
	erow = max(ay+100,by+100);
	scol = min(ax+100,bx+100);
	ecol = max(ax+100,bx+100);
	for( i = srow; i < erow; i++ )
		memset(matrix[i]+scol,color,ecol-scol);
}
int count_color( int color )
{
	int i,j;
	int ret = 0;
	char col = (char)color;
	for( i = 0; i < RECT_SIZE; i++ )
	for( j = 0; j < RECT_SIZE; j++ )
		if( col == matrix[i][j] )
			ret += 1;
	return ret;
}
int main()
{
	int t = 0;
	int n,color,col,i;
	int ax,ay,bx,by;
	while( scanf("%d%d",&n,&color) && n != 0 )
	{
		memset(matrix,0,sizeof(matrix));	
		for( i = 0; i < n; i++ )
		{
			scanf("%d%d%d%d%d",&col,&ax,&ay,&bx,&by);
			color_matrix(matrix,col,ax,ay,bx,by);
		}
		printf("The area of color %d in dataset %d is: %d\n",color,++t,count_color(color));
	}
	return 0;
}
