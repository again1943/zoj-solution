/*
 * =====================================================================================
 *
 *       Filename:  acm1526.cpp
 *
 *    Description:  solutions to zoj 1526
 *
 *        Version:  1.0
 *        Created:  2007年03月10日 18时15分26秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars  
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<math.h>
#include<stdio.h>


#define pi 3.1415926
#define e 2.718281828

int main()
{
	int n;
	double c;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lf",&c);	
		printf("%d\n",c == 1 ? 1:(int)
				(
				(0.5*log10(2*pi*c)+c*log10(c/e))+1
				)
				);
	}
	return 0;
}
