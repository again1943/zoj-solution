/*
 * =====================================================================================
 *
 *       Filename:  1539.cpp
 *
 *    Description:  solution to zoj 1539
 *
 *        Version:  1.0
 *        Created:  2007年05月20日 16时43分43秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#define SIZE 5000001
using namespace std;

int soldier[SIZE] = {0,0,0,1};
int main()
{
	int n;	
	for( int i = 4; i < SIZE; i++ )
		soldier[i] = soldier[i/2]+soldier[i-i/2];
	while( scanf("%d",&n) != -1 )
	{
		if( n < SIZE )
			printf("%d\n",soldier[n]);
		else
			printf("%d\n",soldier[n/2]+soldier[n-n/2]);
	}
	return 0;
}

