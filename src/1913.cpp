/*
 * =====================================================================================
 *
 *       Filename:  1913.cpp
 *
 *    Description:  solution to zoj 1913
 *
 *        Version:  1.0
 *        Created:  2007年10月18日 20时25分27秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio> 
#include<algorithm>
using namespace std;

int main()
{
	int x,y,t,z;
	while( scanf("%d%d",&x,&y) && ( x != 0 && y != 0 ))
	{
		t = 0;
		if( x < y )
			swap(x,y);
		while( 1 )
		{
			if( x%y == 0 || x/y >= 2 )
				break;
			else
			{
				t++;	
				z = x-y;
				x = y;
				y = z;
			}
		}
		if( t % 2 == 0 )
			printf("Stan wins\n");
		else
			printf("Ollie wins\n");
	}
	return 0;
}

