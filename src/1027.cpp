/*
 * =====================================================================================
 *
 *       Filename:  1027.cpp
 *
 *    Description:  solution to zoj 1027
 *
 *        Version:  1.0
 *        Created:  2007年05月19日 22时40分36秒 CST
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
#define SIZE 102

int value[5][5] = 
{
	{5,-1,-2,-1,-3},
	{-1,5,-3,-2,-4},
	{-2,-3,5,-2,-2},
	{-1,-2,-2,5,-1},
	{-3,-4,-2,-1,0}
};
int DP[SIZE][SIZE];

inline int get_code(char c)
{
	switch(c)
	{
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'G':
			return 2;
		case 'T':
			return 3;
		default:
			return 4;
	}
}

int main()
{
	int n;
	int x,y;
	char First[SIZE];
	char Second[SIZE];
	std::scanf("%d",&n);

	while( n-- )
	{
		std::scanf("%d%s",&x,First+1);
		std::scanf("%d%s",&y,Second+1);
				
		DP[0][0] = 0;
		for( int i = 1; i <= x; i++ )
			DP[i][0] = DP[i-1][0] + value[get_code(First[i])][get_code('-')];
		for( int i = 1; i <= y; i++ )
			DP[0][i] = DP[0][i-1] + value[get_code('-')][get_code(Second[i])];

		for( int i = 1; i <= x; i++ )
		for( int j = 1; j <= y; j++ )
		{
			if( First[i] == Second[j] )
				DP[i][j] = DP[i-1][j-1]+
					value[get_code(First[i])][get_code(Second[j])];
			else
			{
				DP[i][j] = std::max(DP[i][j-1]+
						value[get_code('-')][get_code(Second[j])],
				DP[i-1][j]+value[get_code(First[i])][get_code('-')]);					
				DP[i][j] = std::max(DP[i][j],
				 DP[i-1][j-1]+value[get_code(First[i])][get_code(Second[j])]);
			}
		}
		printf("%d\n",DP[x][y]);
	}
	return 0;
}
