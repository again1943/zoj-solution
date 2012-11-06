/*
 * =====================================================================================
 *
 *       Filename:  1360.cpp
 *
 *    Description:  zoj 1360
 *
 *        Version:  1.0
 *        Created:  2007年10月13日 19时29分43秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cmath>
#include<algorithm>
#include<cstdio>

#define SIZE 1000
using namespace std;

struct point_t
{
	int x;
	int y;
}points[SIZE];

struct dist_t
{
	double left;
	double right;
}dist[SIZE];

struct sort_t
{
	bool operator()(const point_t& first, const point_t& second)
	{
		return first.x > second.x;
	}
};

inline dist_t get_dist( point_t& pt, int r )
{
	dist_t ret;
	double half_len = sqrt((double)(r*r-pt.y*pt.y));	
	ret.left = pt.x-half_len;
	ret.right = pt.x+half_len;
	return ret;
}

int get_max( int n, int r )
{
	int count;
	dist_t current;
	sort(points,points+n,sort_t());		
	for( int i = 0; i < n; i++ )
		dist[i] = get_dist(points[i],r);

	count = 1;
	current = dist[0];

	for( int i = 1; i < n; i++ )
	{
		current.left = max(current.left,dist[i].left);
		current.right = min(current.right,dist[i].right);
		if( current.left > current.right )
		{
			count++;
			current = dist[i];
		}
	}
	return count;	
}
int main()
{
	int n,r;
	int flag;
	int count = 0;
	while( scanf("%d%d",&n,&r) && ( n != 0 && r != 0 ))
	{
		flag = true;
		for( int i = 0; i < n; i++ )
		{
			scanf("%d%d",&points[i].x,&points[i].y);
			if( points[i].y > r )
				flag = false;
		}
		printf("Case %d: %d\n",++count,(flag == false)?-1:get_max(n,r));
	}
	return 0;
}

