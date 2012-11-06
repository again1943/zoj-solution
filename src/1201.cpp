/*
 * =====================================================================================
 *
 *       Filename:  1201.cpp
 *
 *    Description:  solution to zoj 1201
 *
 *        Version:  1.0
 *        Created:  2007年10月19日 10时06分56秒 CST
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
using namespace std;
#define SIZE 55

int num[SIZE];
int res[SIZE];

void do_perm(int n)
{
	int result;
	for( int i = 1; i <= n; i++ )	
	{
		result = 0;	
		for( int j = 0; j < n && num[j] != i; j++ )
		{
			if( num[j] > i )
				result++;
		}
		res[i-1] = result;
	}
}

int do_i( int current,int i , int n )
{
	int back = num[i]-num[i-1];
	if( back > 0 )
	{
		while( back != 0 )	
		{
			current++;	
			if( res[current] < 0 )
				back--;
		}

	}
	if( back < 0 )
	{
		while( back != 0 )	
		{
			current--;
			if( res[current] < 0 )
				back++;
		}
	}
	res[current] = i+1;
	if( i  != n -1 )
	{
		while( res[current] > 0 )
			current++;
	}
	else
	{
		for( int i = 0; i < n; i++ )
		{
			if( res[current] < 0 )
			{
				res[current] = n;
				break;
			}
		}
	}
	return current;
}

void do_invs(int n)
{
	int current;

	
	fill(res,res+SIZE,-1);
	res[num[0]] = 1;
	current = num[0]+1;

	for( int i = 1; i < n; i++ )
		current = do_i(current,i,n);
			
}
int main()
{
	int n;
	char c;
	while( scanf("%d",&n) && n != 0 )
	{
		getchar();
		scanf("%c",&c);
		for( int i = 0; i < n; i++ )
			scanf("%d",&num[i]);
		if( c  == 'P' )
			do_perm(n);
		else
			do_invs(n);
		for( int i = 0; i < n; i++ )
			printf("%d%c",res[i],((i==n-1)?'\n':' '));
	}
	return 0;
}
