/*
 * =====================================================================================
 *
 *       Filename:  acm2202_dp.cpp
 *
 *    Description:  solution to zoj 2202
 *
 *        Version:  1.0
 *        Created:  2007年03月15日 21时28分45秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat form Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */


#include<cstdio>
#include<cstring>
#define SIZE 2800 
using namespace std;

int dp[SIZE][SIZE];


int main()
{	
	char line[SIZE];
	int n;

	scanf("%s",line);

	while( strcmp(line,"0") != 0 )
	{
		n = strlen(line);
		for( int i = 0; i < n; i++ )	
			dp[i][i] = line[i] == '0' ? 0:1;			
		for( int i = 0; i < n-1; i++ )
		{
			switch( line[i] )
			{
				case '0':
					dp[i][i+1] = 0;
					break;
				case '1':
					dp[i][i+1] = 
						( line[i+1] == '0' )?1:2;
					break;
				case '2':
					dp[i][i+1] = 
						(line[i+1] == '0' || 
						 line[i+1] > '6' ) ? 1:2;
					break;
				default:
					dp[i][i+1] =
						(line[i+1] == '0')?0:1;
					break;
			}
		}
		for( int j = 2; j < n; j++ )
		for( int i = 0; i+j < n; i++ )
		{
			switch(line[i+j])
			{
				case '0':
					if( line[i+j-1] > '2' )
						dp[i][i+j] = 0;
					else
						dp[i][i+j] = dp[i][i+j-2];
					break;
				case '1':
				case '2':
				case '3':
				case '4':
				case '5':
				case '6':
					if( line[i+j-1] == '0' )
						dp[i][i+j] = dp[i][i+j-1];
					else if( line[i+j-1] >= '3')
						dp[i][i+j] = dp[i][i+j-1];
					else
						dp[i][i+j] = dp[i][i+j-1]+dp[i][i+j-2];
					break;
				default:
					if( line[i+j-1] == '0' )
						dp[i][i+j] = dp[i][i+j-1];
					else if( line[i+j-1] >= '2' )
						dp[i][i+j] = dp[i][i+j-1];
					else
						dp[i][i+j] = dp[i][i+j-1]+dp[i][i+j-2];
					break;	
			}

		}

#ifdef DEBUG
		for( int i = 0; i < n; i++ )
		{
			for( int j = 0; j < n; j++ )
			{
				if( j < i )
					printf("0 ");
				else
					printf("%d ",dp[i][j]);
			}
			printf("\n");
		}
#endif
		printf("%d\n",dp[0][n-1]);
		scanf("%s",line);
		
	}

	return 0;
}

