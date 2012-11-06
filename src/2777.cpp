/*
 * =====================================================================================
 *
 *       Filename:  zoj2777.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2007年02月27日 03时43分47秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include<stdio.h>
#define MAX 1001
int gcd( int m, int n )
{
	int temp;
	int a = m >= n ? m : n;
	int b = m < n ? m : n;
	if( b == 1 )
		return 1;
	else if( a == b )
		return a;
	else
	{
		while( b != 0 )
		{
			temp = a%b;
			a = b;
			b = temp;
		}
		return a;
	}
}

int fact[MAX];

void set_fact( )
{
	int i,j;
	fact[0] = 0;
	fact[1] = 0;

	for( i = 2; i < MAX; i++ )
	{
		fact[i] = fact[i-1];
		for( j = 1; j < i; j++ )
		{
			if( gcd(i,j) == 1 )
				fact[i]++;
		}
	}
}

int main()
{
	int test_case;
	int n,i;	
	set_fact();
	scanf("%d",&test_case);
	for( i = 0; i < test_case; i++ )
	{
		scanf("%d",&n);
		printf("%d %d %d\n",i+1,n,2*fact[n]+3);
	}
	return 0;
}
