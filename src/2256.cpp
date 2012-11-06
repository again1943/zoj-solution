/*
 * =====================================================================================
 *
 *       Filename:  acm2256.cpp
 *
 *    Description:  solution to zoj 2256
 *
 *        Version:  1.0
 *        Created:  2007年03月16日 00时03分23秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
//#include<algorithm>
using namespace std;

struct price_t
{
	bool which;
	int value;
	double cost;
};

int main()
{
	int n;
	price_t price[10];

	for( int i = 1; i <= 7; i++ )
	{
		
		if( i % 2 == 0 )
		{
			if( (double)((8+i)/2-4)*4+20> 18+2.4*i)
			{
				if( i == 5 )
				{
					price[i].value = 30;
					price[i].which = true;
	
				}
				else
				{
					price[i].cost = 18+2.4*i;
					price[i].which = false;
				}
			}
			else
			{
				price[i].value = ((8+i)/2-4)*4+20;
				price[i].which = true;
			}
		}
		else
		{
			if( (double)((8+i)/2-4)*4+22 > 18+2.4*i )
			{
				if( i == 5 )
				{
					price[i].value = 30;
					price[i].which = true;

				}
				else
				{
					price[i].cost = 18+2.4*i;
					price[i].which = false;
				}
			}
			else
			{
				price[i].value = ((8+i)/2-4)*4+22 ;
				price[i].which = true;
			}

		}
	}

	while(scanf("%d",&n)&&n)
	{
		if( n <= 4 )
			printf("10\n");
		else if( n <= 8 )
			printf("%d\n",10+(n-4)*2);
		else 
		{
			int temp = n%8;
			if( temp == 0 )
				printf("%d\n",(n/8)*18);
			else
			{
				if( price[temp].which == true )
					printf("%d\n",(n/8-1)*18+price[temp].value);
				else
					printf("%0.1lf\n",(n/8-1)*18+price[temp].cost);

			}
		}
	}
	return 0;
	
}
