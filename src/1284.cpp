/*
 * =====================================================================================
 *
 *       Filename:  acm1284.cpp
 *
 *    Description:  solution to zoj 1284
 *
 *        Version:  1.0
 *        Created:  2007年03月12日 04时39分34秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
#define SIZE 60001

using namespace std;

int DataSet[SIZE];

void SetData()
{
	DataSet[0] = DataSet[1] = 0;
	for( int i = 2; i < SIZE; i++ )
		DataSet[i] = 1;
	for( int i = 2; i < SIZE/2+1; i++ )	
	for( int j = 2; i*j < SIZE; j++ )
		DataSet[i*j] += i;

}
int main()
{
	int n;

	SetData();
	printf("PERFECTION OUTPUT\n");

	while(scanf("%d",&n) && n )
	{
		if( n == DataSet[n] )	
			printf("%5d  PERFECT\n",n);
		else if( n < DataSet[n] )
			printf("%5d  ABUNDANT\n",n);
		else
			printf("%5d  DEFICIENT\n",n);

	}
	
	printf("END OF OUTPUT\n");
	return 0;

}
