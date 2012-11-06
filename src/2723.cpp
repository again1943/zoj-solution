/*
 * =====================================================================================
 *
 *       Filename:  acm2723.cpp
 *
 *    Description:  solution to zoj 2723
 *
 *        Version:  1.0
 *        Created:  2007年03月29日 17时58分51秒 CST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Fatrat from Mars
 *        Company:  Fatrat
 *
 * =====================================================================================
 */
#include<cstdio>

#define MAX 500001

using namespace std;

bool prime_table[MAX];

void canculate_prime_table()
{
	int i,j;
	prime_table[0] = prime_table[1] = false;	
	for( i = 2; i < MAX; i++ )
		prime_table[i] = true;
	for(i = 2; i*2 < MAX; i++ )
	{
		if( prime_table[i] == true )
		{
			for(j = 2; j*i < MAX; j++ )
				prime_table[i*j] = false;

		}
	}
}

int main()
{
	int n,i;
	bool flag;
	canculate_prime_table();
	while( scanf("%d",&n) != -1 )
	{
		if( n <= 3 )
			printf("No\n");
		else
		{
			flag = false;
			for(i = 2; i < MAX&&i <= n/2; i++ )
			{
				if( n < MAX && prime_table[n] == true )
					break;
				if( prime_table[i] == true && n % i == 0 
						&& prime_table[n/i]==true)
				{
					printf("Yes\n");
					flag = true;
					break;
				}
			}
			if( flag == false )
				printf("No\n"); 
		}
	}
	return 0;
}
