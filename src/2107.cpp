/*
 * =====================================================================================
 *
 *       Filename:  2107.cpp
 *
 *    Description:  solution to zoj 2107
 *
 *        Version:  1.0
 *        Created:  2007年05月03日 07时00分59秒 CST
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
#include<cmath>
#include<algorithm>

#define INFIT	1e1000
#define SMALL_ENOUGH 1e-10
#define MAX_POINTS 100000

struct point_t
{
	double x;
	double y;
};
struct sort_op
{
	bool operator()(const point_t& first,const point_t& second )
	{
		return first.x < second.x;
	}
};

point_t points[MAX_POINTS];

inline double distance( const point_t& first, const point_t& second )
{
	return sqrt((first.x-second.x)*(first.x-second.x)
			+(first.y-second.y)*(first.y-second.y));
}

double nearst_dist(point_t* points, int n)
{
	double temp;
	double min_dist = INFIT;

	for( int i = 0; i < n-2; i++ )
	{
		if( (temp = distance(points[i],points[i+1])) < min_dist )
			min_dist = temp;
		if( (temp = distance(points[i],points[i+2])) < min_dist )
			min_dist = temp;
		if( min_dist < SMALL_ENOUGH )
			return 0;
	}
	if( (temp = distance(points[n-2],points[n-1])) < min_dist )
		min_dist = temp;
	return min_dist;

}

int main()
{
	int n,i;	
	while( scanf("%d",&n)&& n > 0 )
	{
		for( i = 0; i < n; i++ )	
			scanf("%lf%lf",&points[i].x,&points[i].y);
		std::sort(points,points+n,sort_op());
		printf("%0.2lf\n",nearst_dist(points,n)/2);
	}
	return 0;

}

