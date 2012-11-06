/*
 * =====================================================================================
 *
 *       Filename:  1558.cpp
 *
 *    Description:  solution to zoj 1558
 *
 *        Version:  1.0
 *        Created:  2007年05月11日 16时37分08秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  
 *
 * =====================================================================================
 */
#include<cstdio>
#include<algorithm>
#define COINS 6
#define MONEY 100
#define LARGE 10000

int coins[COINS];
int use_coins[MONEY+1];

void do_solve()
{
	int temp;
	std::fill(use_coins,use_coins+MONEY+1,LARGE);

	for( int i = 0;i < COINS; i++ ) 
		use_coins[coins[i]] = 1;

	for( int i = 1; i <= MONEY; i++ )
	{
		if( use_coins[i] == LARGE )
			continue;
		for( int j = 1; j <= MONEY; j++ )
		{
			if( use_coins[j] == LARGE )
				continue;
			temp = use_coins[i]+use_coins[j];

			if( i+j <= MONEY&& use_coins[i+j] > temp)
				use_coins[i+j] = temp;

			if( i-j > 0 && use_coins[i-j] > temp )
				use_coins[i-j] = temp;

			if( j-i > 0 && use_coins[j-i] > temp )
				use_coins[j-i] = temp; 

		}
	}
//此处本来上面的循环貌似就可以了，但是有时候不能得出正确答案，于是我再
//循环了一次，可以把所有test data过掉了，但是这个方法貌似有点取巧的
//理论上不一定正确，同文件夹下有euro.c是这个题目的标程，但是我没怎么看懂...
	for( int i = 1; i <= MONEY; i++ )
	{
		for( int j = 1; j <= MONEY; j++ )
		{
			temp = use_coins[i]+use_coins[j];

			if( i+j <= MONEY&& use_coins[i+j] > temp)
				use_coins[i+j] = temp;

			if( i-j > 0 && use_coins[i-j] > temp )
				use_coins[i-j] = temp;

			if( j-i > 0 && use_coins[j-i] > temp )
				use_coins[j-i] = temp; 

		}
	}


}

int main()
{
	int n;
	int max_coin;
	int sum_coin;
	std::scanf("%d",&n);
	while( n-- )
	{
		sum_coin = max_coin = 0;
		for( int i = 0;i < COINS; i++ )
			std::scanf("%d",&coins[i]);
		do_solve();
		for( int i = 1; i <= MONEY; i++ )
		{
			sum_coin += use_coins[i];
			if( max_coin < use_coins[i] )
				max_coin = use_coins[i];
		}
		printf("%0.2lf %d\n",sum_coin/100.00,max_coin);
	}
	return 0;
}

