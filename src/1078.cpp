/*
 * =====================================================================================
 *
 *       Filename:  1078.cpp
 *
 *    Description:  solution to zoj 1078 
 *
 *        Version:  1.0
 *        Created:  2007年04月25日 06时19分08秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
#include<vector>

void to_digit_on_base(int n, int base,std::vector<int>& digit)
{
	while( n != 0 )
	{
		digit.push_back(n%base);
		n /= base;
	}
}

inline bool test_digit(std::vector<int>& digit)
{
	int i,j;
	for( i = 0,j = digit.size()-1; i < j; i++,j-- )
		if( digit[i] != digit[j] )
			return false;
	return true;
}

int main()
{
	int n;
	std::vector<int> digit,result;

	scanf("%d",&n);
	while( n != 0 )
	{
		for( int i = 2; i <= 16; i++ )
		{
			to_digit_on_base(n,i,digit);
			if( test_digit(digit) == true )
				result.push_back(i);
			digit.clear();
		}
		if( result.size() == 0 )
			printf("Number %d is not a palindrom\n",n);
		else
		{
			printf("Number %d is palindrom in basis",n);
			for( int i = 0; i < result.size(); i++ )
				printf(" %d",result[i]);
			printf("\n");
			result.clear();
		}
		scanf("%d",&n);
	}
	return 0;
}
