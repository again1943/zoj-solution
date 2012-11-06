/*
 * =====================================================================================
 *
 *       Filename:  2829.cpp
 *
 *    Description:  solution to zoj 2829
 *
 *        Version:  1.0
 *        Created:  2007年05月05日 10时47分31秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#define SIZE 100001
#define TEST_SIZE 300000

using namespace std;

int beautiful_number[SIZE];
inline int  get_all()
{
	int count = 0;	
	for( int i = 1; i < TEST_SIZE&& count < SIZE; i++ )
	{
		if( i%3 == 0 || i%5== 0 )
			beautiful_number[count++] = i;
	}
	return count;
}
int main()
{
	int n;
	n = get_all();
#ifdef DEBUG
	printf("%d\n",n);
#endif
	while( scanf("%d",&n) != EOF )
		printf("%d\n",beautiful_number[n-1]);
	return 0;
}

