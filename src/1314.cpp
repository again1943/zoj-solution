/*
 * =====================================================================================
 *
 *       Filename:  1314.cpp
 *
 *    Description:  solution to zoj 1314
 *
 *        Version:  1.0
 *        Created:  2007年05月11日 17时42分18秒 CST
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
#define SIZE 100000

bool generator[SIZE];

bool test_generator(int step, int mod)
{
	int seed = 0;
	int count = 0;
	std::fill(generator,generator+mod,false);	
	while( count < mod )
	{
		seed = seed%mod;
#ifdef DEBUG
		printf("---------------\n");
		printf("seed = %d\n",seed);
		printf("---------------\n");
#endif
		count++;
		if( generator[seed] == false )
			generator[seed] = true;
		else
			return false;
		seed += step;
	}
	return true;
}
int main()
{
	int step,mod;
	while( std::scanf("%d%d",&step,&mod) != -1)
	{
		std::printf("%10d%10d    %s\n\n",step,mod,
				test_generator(step,mod) == true?
				"Good Choice":"Bad Choice"
				);
	}
	return 0;
}
