/*
 * =====================================================================================
 *
 *       Filename:  acm1489.cpp
 *
 *    Description:  solution to zoj 1489 
 *
 *        Version:  1.0
 *        Created:  2007年03月12日 01时48分41秒 CST
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

using namespace std;

int main()
{
	int n;	
	int target,count;
	while( scanf("%d",&n) != -1 )
	{
		if( n == 1 || n % 2 == 0 )	
			printf("2^? mod %d = 1\n",n);
		else
		{
			target = 2;
			count = 1;
			while(1)
			{
				target = (target << 1);
				count++;
				if( target > n &&( (target %= n) == 1) )
					break;
			}
			printf("2^%d mod %d = 1\n",count,n);
		}
	}

	return 0;
}


