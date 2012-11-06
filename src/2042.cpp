/*
 * =====================================================================================
 *
 *       Filename:  2042.cpp
 *
 *    Description:  solution to zoj 2042
 *
 *        Version:  1.0
 *        Created:  2007年10月20日 10时42分10秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

#define NUM_SIZE 10001
#define MOD_SIZE 101

int elem[NUM_SIZE];
bool flag[NUM_SIZE][MOD_SIZE];

inline int increase( int n,int mod )
{
	while( n < 0 )	
		n += mod;
	return n;
}

bool do_test( int num, int mod)
{
	int k;
	memset(flag,0,(num+1)*MOD_SIZE*sizeof(bool));
	
	flag[0][0] = true;
	for( int i = 1; i <=num; i++ )
	for( int j = 0; j < mod; j++ )
	{
		if( flag[i-1][j] == true )
		{
			k = increase((j+elem[i])%mod,mod);
			flag[i][k] = true;

			k = increase((j-elem[i])%mod,mod);
			flag[i][k] = true;
		}
	}
	return flag[num][0];
}

int main()
{
	int test_case;
	int num,mod;
	scanf("%d",&test_case);
	for( int i = 0; i < test_case; i++ )
	{
		if( i != 0 )
			printf("\n");
		scanf("%d%d",&num,&mod);
		for( int j = 1; j <= num; j++ )
			scanf("%d",&elem[j]);
		printf("%s\n",(do_test(num,mod) == true) ? "Divisible":"Not divisible");
	}
	return 0;
}


