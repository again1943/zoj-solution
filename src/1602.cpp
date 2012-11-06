/*
 * =====================================================================================
 *
 *       Filename:  1276.cpp
 *
 *    Description:  solution to zoj 1602
 *
 *        Version:  1.0
 *        Created:  2007年10月22日 13时02分09秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<limits>
using namespace std;

#define SIZE 101

struct matrix_t
{
	int row;
	int col;
};
struct transform_t
{
	int mul;
	int pos;
	matrix_t mtx;
};

matrix_t matrix[SIZE];
transform_t transform[SIZE][SIZE];

int do_transform( int n)
{
	int min_mul;
	int temp;
	int min_pos;
	for( int i = 0; i < n; i++ )	
	{
		transform[i][i].mul = 0;
		transform[i][i].pos = -1;
		transform[i][i].mtx = matrix[i];
	}
	for( int l = 1; l < n; l++ )
	{
		for( int i = 0; i+l < n; i++ )	
		{
			min_mul = min_pos = -1;	
			for( int j = 1; j <= l; j++ )
			{
				temp = transform[i][i+j-1].mul+
					transform[i][i+j-1].mtx.row*
					transform[i][i+j-1].mtx.col*
					transform[i+j][i+l].mtx.col+
					transform[i+j][i+l].mul;
				if( min_mul < 0 || min_mul > temp )	
				{
					min_mul = temp;
					min_pos = i+j-1;
				}
			}
			transform[i][i+l].mul = min_mul;
			transform[i][i+l].pos = min_pos;
			transform[i][i+l].mtx.row = transform[i][min_pos].mtx.row;
			transform[i][i+l].mtx.col = transform[min_pos+1][i+l].mtx.col;
		}
	}
	return transform[0][n-1].mul;
}
int main()
{
	int n;
	while( scanf("%d",&n) != -1 )
	{
		scanf("%d",&matrix[0].row);
		for( int i = 0; i < n-1; i++ )
		{
			scanf("%d",&matrix[i].col);
			matrix[i+1].row = matrix[i].col;
		}
		printf("%d\n",do_transform(n-1));
	}
	return 0;
}


