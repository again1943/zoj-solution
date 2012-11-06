/*
 * =====================================================================================
 *
 *       Filename:  1049.cpp
 *
 *    Description:  solution to zoj 1049
 *
 *        Version:  1.0
 *        Created:  2007年05月04日 08时29分14秒 CST
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
#define pi 3.141592653
using namespace std;

int main()
{
	int n,i,j;
	double x,y,r,dist;
	scanf("%d",&n);
	for( i = 0; i < n ; i++ )
	{
		j = 0;
		r = 0;
		scanf("%lf%lf",&x,&y);	
		dist = sqrt(x*x+y*y);
		while( r < dist )
		{
			j++;
			r = sqrt(100*j/pi);
		}
		printf("Property %d: This property will begin eroding in year %d.\n",i+1,j);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}

