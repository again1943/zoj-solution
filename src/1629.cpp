/*
 * =====================================================================================
 *
 *       Filename:  1629.cpp
 *
 *    Description:  solution to zoj 1629
 *
 *        Version:  1.0
 *        Created:  2007年05月11日 15时16分31秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#define SIZE 501
using namespace std;

int triangle[SIZE];

void triangle_set()
{
	int i;
	triangle[0] = 0;
	triangle[1] = 1;
	for( i = 2; i < SIZE; i++ )
		triangle[i] = triangle[i-1]+i*(3*i+2)/4;
}
int main()
{
	int n;
	triangle_set();
	while( scanf("%d",&n) != -1 )
		printf("%d\n",triangle[n]);
	return 0;
}
