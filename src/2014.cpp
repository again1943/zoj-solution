/*
 * =====================================================================================
 *
 *       Filename:  2014.cpp
 *
 *    Description:  solution to zoj 2014
 *
 *        Version:  1.0
 *        Created:  2007年10月27日 14时07分02秒 CST
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
#include<cstdlib>
#include<cstring>
using namespace std;

#define IMPOSSIBLE 2147483646
#define WEIGHT_RANGE 10004
#define PRICE_ELEM 504

int price[PRICE_ELEM];
int weight[PRICE_ELEM];
int weight_dp[WEIGHT_RANGE];

int main()
{
	int test_case,temp;
	int empty,full,coins,total;
	int min_amount;
	scanf("%d",&test_case);
	for( int t = 0; t < test_case; t++ )
	{
		min_amount = IMPOSSIBLE;

		scanf("%d%d%d",&empty,&full,&coins);		
		total = full-empty;
		memset(weight_dp,-1,sizeof(int)*total+4);
		weight_dp[0] = 0;
		for( int i = 1; i <= coins; i++ )
			scanf("%d%d",&price[i],&weight[i]);
		for( int i = 1; i <= coins; i++ )
		for( int j = 0; (temp = j+weight[i]) <= total; j++ )	
		{
			if( weight_dp[j] != -1 )
			{
				if( weight_dp[temp] == -1 || weight_dp[temp] > weight_dp[j]+price[i] )
					weight_dp[temp] = weight_dp[j]+price[i];
				if( temp == total && weight_dp[temp] < min_amount )
					min_amount = weight_dp[temp];
			}
		}
		if( min_amount == IMPOSSIBLE )
			printf("This is impossible.\n");
		else
			printf("The minimum amount of money in the piggy-bank is %d.\n",min_amount);
		
	}
	return 0;
}



