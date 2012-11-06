/*
 * =====================================================================================
 *
 *       Filename:  2679.cpp
 *
 *    Description:  solution to zoj 2679
 *
 *        Version:  1.0
 *        Created:  2007年05月01日 05时18分33秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<iostream>
int main()
{
	int i,j;
	int test_case;
	int n,x,y,z,sum,temp;
	std::cin >> test_case;
	while(test_case-- )
	{
		std::cin >> n >> x >> y >> z;
		temp = x*1000+y*100+z*10;
		for( i = 9; i >= 1; i-- )
		for( j = 9; j >= 0; j-- )
		{	
			sum = temp+ i*10000+j;
			if( sum%n == 0 )
				goto here;
		}
here:
		if( i == 0 )
			std::cout << 0 << std::endl;
		else
			std::cout << i << " " << j <<" " << sum/n << std::endl;
	}
	return 0;
}

