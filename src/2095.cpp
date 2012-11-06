/*
 * =====================================================================================
 *
 *       Filename:  acm2095.cpp
 *
 *    Description:  solution to zoj 2095
 *
 *        Version:  1.0
 *        Created:  2007年03月12日 02时12分52秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<vector>
#include<cstdio>

#define SIZE 500001
using namespace std;

struct num_t
{
	bool prime;
	int sum;
}DataSet[SIZE];

void set()
{
	for( int i = 0; i < SIZE ; i++ )	
	{
		DataSet[i].prime = true;
		DataSet[i].sum = 1;
	}

	for( int i = 2; i < SIZE/2+1; i++ )
	for( int j = 2; i*j < SIZE;j++ ) 
	{
		DataSet[i*j].prime = false;	
		DataSet[i*j].sum += i;
	}
}

int main()
{
	int n,m;

	set();

 	scanf("%d",&m);

	while( m--  )
	{	
		scanf("%d",&n);

		if( n == 1 )	
			printf("0\n");
		else
			printf("%d\n",DataSet[n].sum);

	}
	return 0;
}



