/*
 * =====================================================================================
 *
 *       Filename:  acm1938.cpp
 *
 *    Description:  solution to zoj 1938
 *
 *        Version:  1.0
 *        Created:  2007年03月12日 02时56分04秒 CST
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

long long int result( long long int n, long long int m)
{		
	int x,y;
	int start,end;
	long long int r;
	
	if( m > n )
		return 0;
	else if( m == 0 || m == n )
		r = 1;
	else if( m == 1 || m == n-1 )
		r = n;
	else if( m == 2 || m == n-2 )
		r = (n*(n-1))/2;
	else if( m == 3 || m == n-3 )
		r = (n*(n-1)*(n-2))/6;
	else if( m == 4 || m == n-4 )
		r = (n*(n-1)*(n-2)*(n-3))/24;
	else
	{
		r = 1;
		x = m > n-m ? m:n-m;	
		y = n-x;

		start = x+1;	
		end = n;

		for( int i = start,j = 2; i <= end; i++ )
		{
			r *= i;
			if( j <= y && r % j == 0 )
			{
				r /= j;
				j++;
			}
		}
	}
	return r;
}

int main()
{
	long long int m,n;
	
	scanf("%lld%lld",&n,&m);

	while( m != 0 || n != 0 )
	{
		printf("%lld\n",result(n,m));
		scanf("%lld%lld",&n,&m);
	}
		
	return 0;
}
