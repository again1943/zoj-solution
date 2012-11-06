/*
 * =====================================================================================
 *
 *       Filename:  1716.cpp
 *
 *    Description:  solution to zoj 1716
 *
 *        Version:  1.0
 *        Created:  2007年05月18日 11时39分21秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
#include<algorithm>
#define FIELD_SIZE 100

int field[FIELD_SIZE][FIELD_SIZE];

using namespace std;

int main()
{
	int n,w,h;
	int temp,max;
	int x,y,i,j;
	while( scanf("%d",&n) && n > 0 )
	{
		scanf("%d%d",&h,&w);
		for( i = 0; i <= h; i++ )
			fill(field[i],field[i]+w+1,0);
		for( i = 0; i < n; i++ )
		{
			scanf("%d%d",&x,&y);
			field[x][y] = 1;
		}
		scanf("%d%d",&x,&y);
		for( i = 1; i <= h; i++ )
		for( j = 1; j <= w; j++ )
			field[i][j] += field[i-1][j]+field[i][j-1]-field[i-1][j-1];
		max = 0;
		for( i = x; i <= h; i++ )
		for( j = y; j <= w; j++ )
		{
			temp = field[i][j]+field[i-x][j-y]-field[i-x][j]-field[i][j-y];
			if( max < temp )
				max = temp;
		}
		printf("%d\n",max);
	}
	return 0;
}
