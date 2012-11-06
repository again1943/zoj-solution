/*
 * =====================================================================================
 *
 *       Filename:  1101.cpp
 *
 *    Description:  solution to zoj 1101
 *
 *        Version:  1.0
 *        Created:  2007年05月04日 23时28分25秒 CST
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
#include<algorithm>
using namespace std;
#define SIZE 1200

int wager[SIZE];
int main()
{
	int n,i;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )
			scanf("%d",wager+i);
		sort(wager,wager+n);
#ifdef DEBUG
		printf("----------------------\n");
		for( int j = 0; j < n; j++ )
			printf("%d ",wager[j]);
		printf("\n---------------------\n");
#endif
		if( n < 4 )
		{
			i = -1;
			goto here;
		}
		for( i = n-1; i >= 0; i-- )
		{
			for( int s = 0; s < n&& wager[s] <= wager[i]; s++ )	
			{
				if( s == i )
					continue;
			for( int t = s+1; t < n&& wager[s]+wager[t] <= wager[i]; t++ )
			{
				if( t == i )
					continue;
			for( int k = t+1; k < n&&wager[s]+wager[t]+wager[k] <= wager[i]; k++ )
			{
				if( k == i )
					continue;
				if( wager[s]+wager[t]+wager[k]== wager[i] )
					goto here;
			}
			}
			}
		}
here:
		if( i >= 0 )
			printf("%d\n",wager[i]);
		else
			printf("no solution\n");
	}
	return 0;
}

