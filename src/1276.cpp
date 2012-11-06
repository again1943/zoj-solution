/*
 * =====================================================================================
 *
 *       Filename:  1276.cpp
 *
 *    Description:  solution to zoj 1276
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

#define SIZE 12

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

void do_transform( int n)
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
}
void do_print(int start,int end)
{
	if( start == end )
		printf("A%d",start+1);
	else if( start + 1 == end )
		printf("(A%d x A%d)",start+1,end+1);
	else
	{
		printf("(");
		do_print(start,transform[start][end].pos);
		printf(" x ");
		do_print(transform[start][end].pos+1,end);
		printf(")");
	}
}
//(A1 x (A2 x A3))
int main()
{
	int n;	
	int test_case = 0;
	while( scanf("%d",&n) && n != 0 )
	{
		for( int i = 0; i < n; i++ )					
			scanf("%d%d",&matrix[i].row,&matrix[i].col);
		do_transform(n);
		printf("Case %d: ",++test_case);
		do_print(0,n-1);
		printf("\n");
	}
	return 0;
}


