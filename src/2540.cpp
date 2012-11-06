/*
 * =====================================================================================
 *
 *       Filename:  2540.cpp
 *
 *    Description:  solution to zoj 2540
 *
 *        Version:  1.0
 *        Created:  2007年05月01日 11时59分38秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<utility>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

#define eps 1e-10

inline double line_len(const std::pair<double,double> &x,const std::pair<double,double> &y)
{
	return std::sqrt((x.first-y.first)*(x.first-y.first)+
			(x.second-y.second)*(x.second-y.second));
}

inline bool equal( double x,double y)
{
	return std::fabs(x-y) < eps;
}

bool determine(const std::pair<double,double>& a,const std::pair<double,double>& b,
		const std::pair<double,double>& c,const std::pair<double,double>& d)
{
	double x = line_len(a,b);
	double y = line_len(a,c);
	double z = line_len(a,d);

	double max = std::max(x,std::max(y,z));
	if( equal(max,x))
	{
		max = line_len(c,d);
		if( equal(y,z)&&equal(y*y+z*z,max*max)&&equal(max,x))
			return true;
		else
			return false;
	}
	if( equal(max,y))
	{
		max = line_len(b,d);
		if( equal(x,z)&&equal(x*x+z*z,max*max)&&equal(max,y))
			return true;
		else
			return false;
	}
	else
	{
		max = line_len(c,b);
		if( equal(y,x)&&equal(y*y+x*x,max*max)&&equal(max,z))
			return true;
		else
			return false;
	}
}


int main()
{
	int test_case,t;
	std::pair<double,double>point[4];

	t = 0;
	std::cin >> test_case;
	while( test_case--)
	{
		if( t++ )
			std::cout << std::endl;
	
		for( int i = 0; i < 4; i++ )
			std::cin >> point[i].first >> point[i].second;
		if( determine( point[0],point[1],point[2],point[3]) == true )
			std::cout << "Case " << t << ":" << std::endl
				<< "Yes" << std::endl;
		else
			std::cout << "Case " << t << ":" << std::endl
				<< "No" << std::endl;

	}
	return 0;
}

