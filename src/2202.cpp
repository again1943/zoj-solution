/*
 * =====================================================================================
 *
 *       Filename:  acm2202.cpp
 *
 *    Description:  solution to zoj 2202
 *
 *        Version:  1.0
 *        Created:  2007年03月15日 23时25分35秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  
 *
 * =====================================================================================
 */
#include<cstdio>
#include<cstring>

#define SIZE 6005
using namespace std;


char line[SIZE];
int dp[SIZE];

int main()
{
	int n;
	scanf("%s",line);	

	while( strcmp(line,"0") != 0 )
	{
		n = strlen(line);	
		dp[0] = 1;

		switch( line[1] )
		{
			case '0':
				dp[1] = 1;
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
				if( line[0] > '2' )
					dp[1] = 1;
				else
					dp[1] = 2;
				break;
			default:
				if( line[0] == 1 )
					dp[1] = 2;
				else
					dp[1] = 1;
				break;
		}

		for( int i = 2; i < n; i++ )
		{
			switch(line[i])	
			{
				case '0':	
					if( line[i-1] > '2' )
						dp[i] = 0;
					else
						dp[i] = dp[i-2];
					break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
					if( line[i-1] == '0')
						dp[i] = dp[i-1];
					else if( line[i-1] >= '3')
						dp[i] = dp[i-1];
					else
						dp[i] = dp[i-1]+dp[i-2];
					break;
				default:
					if( line[i-1] == '0')
						dp[i]= dp[i-1];
					else if( line[i-1] >= '2' )
						dp[i] = dp[i-1];
					else
						dp[i] =dp[i-1]+dp[i-2];
					break;
			}
		}
		printf("%d\n",dp[n-1]);
		scanf("%s",line);
	}

	return 0;
}

