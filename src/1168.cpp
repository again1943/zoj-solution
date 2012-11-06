/*
 * =====================================================================================
 *
 *       Filename:  acm1168.cpp
 *
 *    Description:  solution to zoj 1168
 *
 *        Version:  1.0
 *        Created:  2007年03月10日 23时04分20秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>

using namespace std;

int cubic[21][21][21];

void init()
{
	int i,j,k;	
	for(  i = 0; i <= 20; i++ )
	for( j = 0; j <= 20; j++ )
		cubic[0][i][j] = cubic[i][0][j] = cubic[i][j][0] = 1;
	for( i = 1; i <= 20; i++ )	
	for( j = 1; j <= 20; j++ )
	for( k = 1; k <= 20; k++ )
		cubic[i][j][k] = -1;

}

int function( int a,int b, int c)
{
	if( cubic[a][b][c] > 0 )	
		return cubic[a][b][c];
	if( a < b && b < c )
		return (cubic[a][b][c] = function(a,b,c-1)+
				function(a,b-1,c-1)-function(a,b-1,c));
	else
		return (cubic[a][b][c] = function(a-1,b,c)+
				function(a-1,b-1,c)+function(a-1,b,c-1)
				-function(a-1,b-1,c-1));
}
int main()
{
	int a,b,c;	
	init();
	scanf("%d%d%d",&a,&b,&c);

	while( a != -1 || b != -1 || c != -1 )
	{
		if( a <= 0 || b <= 0 || c <= 0 )
			printf("w(%d, %d, %d) = %d\n",a,b,c,function(0,0,0 ));
		else if( a > 20 || b > 20 || c > 20 )
			printf("w(%d, %d, %d) = %d\n",a,b,c,function(20,20,20 ));
		else
			printf("w(%d, %d, %d) = %d\n",a,b,c,function(a,b,c ));
		scanf("%d%d%d",&a,&b,&c);
	}
}

