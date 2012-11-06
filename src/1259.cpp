/*
 * =====================================================================================
 *
 *       Filename:  1259.cpp
 *
 *    Description:  solution to zoj 1259
 *
 *        Version:  1.0
 *        Created:  2007年10月22日 18时27分07秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
using namespace std;
#define N_SIZE 1024

int order[N_SIZE];
int stack[N_SIZE];

bool do_check( int n )
{
	int stack_top = 0;	
	int order_top = 0;

	for( int i = 1; i <= n; i++ )
	{
		if( i < order[order_top] )	
		{
			if( stack_top == 0 || stack[stack_top-1] < i )
				stack[stack_top++] = i;
			else
				return false;
		
		}
		else if( i > order[order_top] )
		{
			if( stack_top != 0 && stack[stack_top-1] == order[order_top])
			{
				stack_top--;		 
				order_top++;	
			}
			else
				return false;
		}
		else
		{
			order_top++;
			while( stack_top != 0 && stack[stack_top-1] == order[order_top])	
			{
				stack_top--;	
				order_top++;
			}
		}
	}
	if( stack_top + order_top != n )
		return false;
	while( order_top <= n && stack_top > 0 && stack[stack_top-1] == order[order_top] )
	{
		stack_top--;
		order_top++;
	}
	if( stack_top == 0 && order_top == n )
		return true;
	else
		return false;
}
int main()
{
	int n,k;
	while( scanf("%d",&n) && n != 0 )
	{
		while( scanf("%d",&k) && k != 0 )	
		{
			order[0] = k;
			for( int i = 1; i < n; i++ )
				scanf("%d",&order[i]);
			printf("%s\n",do_check(n) == true ? "Yes":"No");
		}
		printf("\n");
	}
	return 0;
}


