/*
 * =====================================================================================
 *
 *       Filename:  2402.cpp
 *
 *    Description:  solution to zoj 2402
 *
 *        Version:  1.0
 *        Created:  2007年08月21日 13时10分57秒 CST
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

#define N_SIZE 11
#define M_SIZE 2001

using namespace std;

long long matrix[N_SIZE][M_SIZE];

void set_matrix()
{
	for( int i = 1; i < M_SIZE; i++ )
		matrix[1][i] = 1;
	for( int i = 1; i < N_SIZE; i++ )	
	for( int j = 1; j < M_SIZE; j++ )
	{
		for( int k = i-1; k <= j/2; k++ )
		{
			matrix[i][j] += matrix[i-1][k];
		}
	}
}

int main()
{
	long long result;
	int n,m;
	int test_case;
	scanf("%d",&test_case);
	set_matrix();
	for( int i = 1; i <= test_case; i++ )
	{
		scanf("%d%d",&n,&m);
		result = 0;
		for( int j = 1; j <= m; j++ )
			result += matrix[n][j];
		printf("Case %d: n = %d, m = %d, # lists = %lld\n",i,n,m,result);
	}
	return 0;
}

