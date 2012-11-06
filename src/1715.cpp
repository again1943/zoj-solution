/*
 * =====================================================================================
 *
 *       Filename:  acm1715.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2006年11月12日 09时49分40秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include<cstdio>
#define DAY_MAX 100
using namespace std;

int day[DAY_MAX];

void init()
{
	for( int i = 0; i < DAY_MAX; i++ )
		day[i] = 0;
}

int find_max()
{
	int temp = day[0];
	int max = 0;
	for( int i =1; i < DAY_MAX; i++ )
		if( temp < day[i] )
		{
			temp = day[i];
			max = i;
		}
	return max;
}
int main()
{
	int N,Q;

	int n,num;
	int result;
	scanf("%d%d",&N,&Q);
	while( N != 0 && Q != 0 )
	{
		init();
		for( int i = 0; i < N; i++ )
		{
			scanf("%d",&n);
			for( int j = 0; j < n; j++ )
			{
				scanf("%d",&num);
				day[num]++;
			}
		}
			
		result = find_max();
		if( day[result] < Q )
			printf("0\n");
		else
			printf("%d\n",result );
		scanf("%d%d",&N,&Q);

	}
	return 0;
}

