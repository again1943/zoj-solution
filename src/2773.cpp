/*
 * =====================================================================================
 *
 *       Filename:  zoj2773.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2007年02月27日 06时20分08秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include<stdio.h>
int main()
{
	long long int test_case;
	long long int n,i,result;
	scanf("%lld",&test_case);
	for( i = 0; i < test_case;i++ )
	{
		scanf("%lld",&n);
		result = (n+1)*(n+1)*(n+1)*(n+1)-n*(2*n*n+5*n+4)-1;
		result /= 4;
		result += n*(n+1)*(2*n+3)/2;
		result /= 2;
		printf("%lld %lld %lld\n",i+1,n,result);
	}
	return 0;
}
