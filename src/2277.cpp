/*
 * =====================================================================================
 *
 *       Filename:  acm2277.cpp
 *
 *    Description:  silution to zoj 2277
 *
 *        Version:  1.0
 *        Created:  2007年03月13日 01时04分06秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
#include<cmath>

#define eps 1e-10

using namespace std;

double cache[10];

int left_most( long double n)
{
	int i;
	double result = n*log10(n);
	long long int x = (long long int)result;	
		
	if( fabs(n) < eps )
		return 0;
	for( i = 2; i < 10; i++ )		
	{
		if( x+cache[i] > result )
			break;
	}
	return i-1;
}
int main()
{
	double n;

	for( int i = 2; i < 10; i++ )
		cache[i] = log10((double)i);

	while( scanf("%lf",&n) != -1 )
		printf("%d\n",left_most(n));
	return 0;
}
