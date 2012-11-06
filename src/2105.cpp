/*
 * =====================================================================================
 *
 *       Filename:  2105.cpp
 *
 *    Description:  solution to zoj 2105
 *
 *        Version:  1.0
 *        Created:  2007年05月03日 09时36分29秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<iostream>

int period( int a, int b)
{
	int temp;
	int x = (a+b)%7;	
	int y = (x*a+b)%7;

#ifdef DEBUG
	std::cout << "x = " << x << ",y = " << y << std::endl;
#endif
	int m = y;
	int n = (m*a+x*b)%7;
	int p = 1;
	while( m != x || n != y )
	{
		temp = n;
		n = (n*a+m*b)%7;
		m = temp;
#ifdef DEBUG
		std::cout << "m = " << m << ",n = " << n << ",p = " << p+1 << std::endl;

#endif
		p++;
	}

	return p;
}

int main()
{
	int m,n,t,s;
	int x,y,z;
	int cycle;
	while( std::cin >> x >> y >> z  && (x != 0 || y != 0 || z != 0) )
	{
		if( z <= 2 )
			std::cout << 1 << std::endl;
		else
		{
			cycle = period(x,y);
			if( cycle == 1 )
				std::cout << (x+y)%7 << std::endl;
			else
			{
				z = (z-2)%cycle;
				m = n = 1;
				while( z > 0 )
				{
					t = m;
					m = (m*x+n*y)%7;
					n = t;
					z--;
				}
				std::cout << m << std::endl;
			}
		}
	}
	return 0;
}
