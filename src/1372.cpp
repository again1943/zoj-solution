/*
 * =====================================================================================
 *
 *       Filename:  1372.cpp
 *
 *    Description:  solution to zoj 1372
 *
 *        Version:  1.0
 *        Created:  2007年04月29日 21时52分35秒 CST
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
#include<vector>
#include<queue>
#define MAX_POINTS 50

struct route_t
{
	int start;
	int end;
	int dist;
};

struct queue_op
{
	bool operator()(const route_t& first, const route_t& second )	
	{
		return first.dist > second.dist;
	}
};

inline int find_root(int* points, int start)
{
	while( points[start] >= 0)
		start = points[start];
	return start;
}
int network(int n,std::priority_queue<route_t,std::vector<route_t>,queue_op>&routes)
{
	int root,sec_root;
	int len = 0;
	route_t temp;
	int points[MAX_POINTS];	
	std::fill(points,points+n,-1);
	while( points[0]+n > 0 && routes.empty() != true )
	{
		temp = routes.top();		
		routes.pop();
		if( points[temp.start] < 0 && points[temp.end] < 0 )		
		{
			points[temp.start] += points[temp.end];
			points[temp.end] = temp.start;
			len += temp.dist;
		}
		else if(points[temp.start] < 0 &&  points[temp.end] >= 0 )
		{
			if( (root = find_root(points,temp.end)) != temp.start )
			{
				points[temp.start] += points[root];
				points[root] = temp.start;
				len += temp.dist;
			}
		}
		else if( points[temp.start] >= 0 &&  points[temp.end] < 0 )
		{
			if( (root = find_root(points,temp.start)) != temp.end )
			{
				points[root] += points[temp.end];
				points[temp.end] = temp.start;
				len += temp.dist;
			}
		}
		else
		{
			if( (root = find_root(points,temp.start))
					!=(sec_root = find_root(points,temp.end)))
			{
				points[root] += points[sec_root];		
				points[sec_root] = root;
				len += temp.dist;
			}
		}

	}
	return len;
}

int main()
{
	int n,line;
	route_t temp;
	std::priority_queue<route_t,std::vector<route_t>,queue_op>routes;
	std::scanf("%d",&n);
	while( n != 0 )
	{
		std::scanf("%d",&line);
		for( int i = 0; i < line; i++ )
		{
			std::scanf("%d%d%d",&temp.start,&temp.end,&temp.dist);
			if( (temp.start--) > (temp.end--) )
				std::swap(temp.start,temp.end);
			routes.push(temp);
		}
		std::printf("%d\n",network(n,routes));
		while( routes.empty() != true )
			routes.pop();
		std::scanf("%d",&n);	
	}
	return 0;
}

