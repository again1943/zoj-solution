/*
 * =====================================================================================
 *
 *       Filename:  acm2486.cpp
 *
 *    Description:  solution to zoj 2486
 *
 *        Version:  1.0
 *        Created:  2007年03月10日 21时31分09秒 CST
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

int main()
{
	double x,y;	
	while( scanf("%lf%lf",&x,&y ) != -1 )
		printf("%.0lf\n",pow(y,1.0/x));
	return 0;
			
}

