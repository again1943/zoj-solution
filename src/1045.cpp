/*
 * =====================================================================================
 *
 *       Filename:  acm1045.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2007年02月28日 20时29分26秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:   (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include<cmath>
#include<cstdio>
#define MAX 521
using namespace std;

int X[MAX];

void set_map()
{
	double sum = 0.50;
	int pos = 1;
	int i = 1;
	while( pos < MAX )
	{	
		while( sum < (double)pos/100 )	
		{
			i++;
			sum += 1/(double)(i+1);
		}
		X[pos++] = i;
	}
}
int main()
{
	double c;
	set_map();
	scanf("%lf",&c);
	while( fabs(c) > 1e-10 )
	{
		int temp = (int)((c+0.001)*100);
		printf("%d card(s)\n",X[temp]);	
		scanf("%lf",&c);
	}
	return 0;
}
