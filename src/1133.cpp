/*
 * =====================================================================================
 *
 *       Filename:  1133.cpp
 *
 *    Description:  solution to zoj 1133
 *
 *        Version:  1.0
 *        Created:  2007年05月04日 10时49分34秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
#define MAX 100
int wheel[] =
{		1, 2, 2, 4, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 
		2, 6, 4, 6, 8, 4, 2, 4, 2, 4, 14, 4, 6, 2, 10, 2, 6, 6, 4, 2, 
		4, 6, 2, 10, 2, 4, 2, 12, 10, 2, 4, 2, 4, 6, 2, 6, 4, 6, 6, 6, 
		2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 4, 6, 8, 6, 10, 2, 4, 6, 2, 6, 
		6, 4, 2, 4, 6, 2, 6, 4, 2, 6, 10, 2, 10, 2, 4, 2, 4, 6, 8, 4, 
		2, 4, 12, 2, 6, 4, 2, 6, 4, 6, 12, 2, 4, 2, 4, 8, 6, 4, 6, 2, 
		4, 6, 2, 6, 10, 2, 4, 6, 2, 6, 4, 2, 4, 2, 10, 2, 10, 2, 4, 6, 
		6, 2, 6, 6, 4, 6, 6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 6, 4, 8, 
		6, 4, 6, 2, 4, 6, 8, 6, 4, 2, 10, 2, 6, 4, 2, 4, 2, 10, 2, 10, 
		2, 4, 2, 4, 8, 6, 4, 2, 4, 6, 6, 2, 6, 4, 8, 4, 6, 8, 4, 2, 
		4, 2, 4, 8, 6, 4, 6, 6, 6, 2, 6, 6, 4, 2, 4, 6, 2, 6, 4, 2, 
		4, 2, 10, 2, 10, 2, 6, 4, 6, 2, 6, 4, 2, 4, 6, 6, 8, 4, 2, 6, 
		10, 8, 4, 2, 4, 2, 4, 8, 10, 6, 2, 4, 8, 6, 6, 4, 2, 4, 6, 2, 
		6, 4, 6, 2, 10, 2, 10, 2, 4, 2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 
		6, 6, 6, 4, 6, 8, 4, 2, 4, 2, 4, 8, 6, 4, 8, 4, 6, 2, 6, 6, 
		4, 2, 4, 6, 8, 4, 2, 4, 2, 10, 2, 10, 2, 4, 2, 4, 6, 2, 10, 2, 
		4, 6, 8, 6, 4, 2, 6, 4, 6, 8, 4, 6, 2, 4, 8, 6, 4, 6, 2, 4, 
		6, 2, 6, 6, 4, 6, 6, 2, 6, 6, 4, 2, 10, 2, 10, 2, 4, 2, 4, 6, 
		2, 6, 4, 2, 10, 6, 2, 6, 4, 2, 6, 4, 6, 8, 4, 2, 4, 2, 12, 6, 
		4, 6, 2, 4, 6, 2, 12, 4, 2, 4, 8, 6, 4, 2, 4, 2, 10, 2, 10, 6, 
		2, 4, 6, 2, 6, 4, 2, 4, 6, 6, 2, 6, 4, 2, 10, 6, 8, 6, 4, 2, 
		4, 8, 6, 4, 6, 2, 4, 6, 2, 6, 6, 6, 4, 6, 2, 6, 4, 2, 4, 2, 
		10, 12, 2, 4, 2, 10, 2, 6, 4, 2, 4, 6, 6, 2, 10, 2, 6, 4, 14, 4, 
		2, 4, 2, 4, 8, 6, 4, 6, 2, 4, 6, 2, 6, 6, 4, 2, 4, 6, 2, 6, 
		4, 2, 4, 12, 2, 12 
};

/* to defact a very large integer number, the factors are in array "factors"*/
int defact (long long n0, int max_n_factors, long long *factors)
{
	long long n = n0, d, q;
  	int n_factors = 0;
  	int w = 0;
  	int END = sizeof(wheel)/sizeof(int);

  	if(n <= 1)
    		return n_factors;
  	d = 2;
  	do
    	{
      		q = n / d;
      		while (n == q * d)
		{
	  		factors[n_factors++] = d;
	  		n = q;
	  		q = n / d;
		}
      		
		d += wheel[w++];
      		
		if (w == END)
			w = 5;
    	}while (d <= q);

  	if (n != 1 || n0 == 1)
      		factors[n_factors++] = n;

  	return n_factors;
}
inline int get_digit_sum( long long n )
{
	int sum = 0;
	while( n != 0 )
	{
		sum += n%10;
		n /= 10;
	}
	return sum;
}
bool test_smith( long long n )
{
	long long fact[MAX];
	int sum,fact_sum;
	int nfact;
	nfact = defact(n,MAX,fact);
	if( nfact > 1 )
	{
		sum = get_digit_sum(n);	
		fact_sum = 0;
		for( int i = 0; i < nfact; i++ )
			fact_sum += get_digit_sum(fact[i]);
		return sum == fact_sum;
	}
	return false;
	
}
int main()
{
	long long n;
	while( scanf("%lld",&n) && n != 0 )
	{
		n++;
		while( test_smith(n) != true )
			n++;
		printf("%lld\n",n);
	}
	return 0;
}
