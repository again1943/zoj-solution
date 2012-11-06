/*
 * =====================================================================================
 *
 *       Filename:  acm1543.cpp
 *
 *    Description:  solution to zoj 1543
 *
 *        Version:  1.0
 *        Created:  2007年03月15日 19时24分07秒 CST
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
#include<queue>

using namespace std;

int main()
{
	int n;
	double elem,x,y;
	priority_queue<double>stripie;
	
	while( scanf("%d",&n) != -1 )
	{
		for( int i = 0; i < n; i++ )
		{
			scanf("%lf",&elem);
			stripie.push(elem);
		}
		
		while( stripie.size() != 1 )
		{
			x = stripie.top();	
			stripie.pop();
			y = stripie.top();
			stripie.pop();

			stripie.push(2*sqrt(x*y));
		}
			
		printf("%0.3lf\n",stripie.top());
		stripie.pop();
	}

	return 0;
}
