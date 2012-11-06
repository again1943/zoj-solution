/*
 * =====================================================================================
 *
 *       Filename:  1893.cpp
 *
 *    Description:  solution to zoj 1893
 *
 *        Version:  1.0
 *        Created:  2007年10月23日 18时03分11秒 CST
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
using namespace std;

long who_win( int n )
{
	long time = 1;		
	long x = 1;
	while( 1 )
	{
		x *= 9;	
		time++;
		if( x >=  n )
			break;
		x *= 2;
		time++;
		if( x >= n )
			break;
			
	}
	return time%2;
}

int main()
{
	long n;
	while( scanf("%ld",&n) != -1 )
		printf("%s wins.\n",( n == 1 || who_win(n) == 0) ?"Stan":"Ollie");
	return 0;
}

