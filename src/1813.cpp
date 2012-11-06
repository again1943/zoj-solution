/*
 * =====================================================================================
 *
 *       Filename:  1813.cpp
 *
 *    Description:  solution to zoj 1813
 *
 *        Version:  1.0
 *        Created:  2007年05月01日 12时36分24秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cmath>
#include<cstdio>

#define PI 3.1415927
#define inch_to_mile 63360
#define sec_to_hour 3600
int main()
{
	int t = 0;
	int revolution;
	double diameter,time,perimeter;
	while( std::scanf("%lf%d%lf",&diameter,&revolution,&time) && revolution != 0 )
	{
		perimeter = diameter*PI*revolution/inch_to_mile;
		std::printf("Trip #%d: %0.2lf %0.2lf\n",++t,
				perimeter,(perimeter*sec_to_hour/time));
	}
	return 0;
}
