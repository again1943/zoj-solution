/*
 * =====================================================================================
 *
 *       Filename:  2259.cpp
 *
 *    Description:  solution to zoj 2259
 *
 *        Version:  1.0
 *        Created:  2007年04月29日 02时09分04秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cmath>
#include<cstdio>
#include<utility>
struct triple_t
{
	double one;
	double two;
	double three;
};

inline double dist(const std::pair<double,double>& x,const std::pair<double,double>& y)
{
	return std::sqrt((x.first-y.first)*(x.first-y.first)
			+(x.second-y.second)*(x.second-y.second));
}
inline void smart_bomb(const std::pair<double,double>& x,
		const std::pair<double,double>& y,
		const std::pair<double,double>& z,
		triple_t& retval)
{
	double dist_xy = dist(x,y);
	double dist_xz = dist(x,z);
	double dist_yz = dist(y,z);
	retval.one = (dist_xy+dist_xz-dist_yz)/2;
	retval.two = (dist_xy+dist_yz-dist_xz)/2;
	retval.three = (dist_xz+dist_yz-dist_xy)/2;
}


int main()
{
	std::pair<double,double>point[3];
	triple_t retval;
	while( std::scanf("%lf%lf",&point[0].first,&point[0].second) != -1 )
	{
		std::scanf("%lf%lf",&point[1].first,&point[1].second);
		std::scanf("%lf%lf",&point[2].first,&point[2].second);

		smart_bomb(point[0],point[1],point[2],retval);
		std::printf("%0.6lf\n%0.6lf\n%0.6lf\n",retval.one,retval.two,retval.three);
	}
	return 0;
}
