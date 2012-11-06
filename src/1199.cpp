/*
 * =====================================================================================
 *
 *       Filename:  zoj1199.cpp
 *
 *    Description:  solution to zoj 1199
 *
 *        Version:  1.0
 *        Created:  2007年04月05日 11时55分17秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<iostream>
#include<cmath>
#include<utility>
using namespace std;

#define eps 1e-10

struct circle_t
{
	int x,y;
	int r;
};

inline bool cal_possible( circle_t& first,circle_t& second)
{
	if(first.r == second.r )
		return false;
	if((first.x-second.x)*(first.x-second.x)+
		(first.y-second.y)*(first.y-second.y)
		<= (first.r-second.r)*(first.r-second.r))
		return false;
	return true;		
}

inline pair<double,double> cal_result(circle_t& first,circle_t& second )
{

	double x = (first.x*second.r-second.x*first.r)*1.0/(second.r-first.r);
	double y = (first.y*second.r-second.y*first.r)*1.0/(second.r-first.r);

	if( fabs(x) < eps )
		x = 0.00;
	if( fabs(y) < eps )
		y = 0.00;
	
	return make_pair(x,y);
}

int main()
{
	int test_case;
	pair<double,double> result;
	circle_t first,second;

	cin >> test_case;
	for( int i = 0; i < test_case; i++ )
	{
		cin >> first.x >> first.y >> first.r
		>> second.x >> second.y >> second.r;
		if( cal_possible(first,second) == false )
			cout << "Impossible." << endl;
		else
		{
			result = cal_result(first,second);
			cout.precision(2);
			cout << fixed 
				<< result.first  << " "
				<< result.second << endl;
		}
	}
	return 0;
}

