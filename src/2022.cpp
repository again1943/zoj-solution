/*
 * =====================================================================================
 *
 *       Filename:  acm2022.cpp
 *
 *    Description:  solution to zoj 2022
 *
 *        Version:  1.0
 *        Created:  2007年03月22日 03时47分47秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
using namespace std;

int base[] ={5,25,125,625,3125,15625,78125,
		390625,1953125,9765625,48828125,244140625};

int main()
{
	int n,i,j,zeros;
	int num;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		zeros = 0;
		scanf("%d",&num);
		for( j = 0; j < 12 && base[j] <= num; j++ )
			zeros += num/base[j];
		printf("%d\n",zeros);
	}
	return 0;
}
