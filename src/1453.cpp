#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
#define TREE_CNT 102
struct point
{
	int x,y;
}tree[TREE_CNT];

struct sort_t
{
	bool operator()(const point& first,const point& second)
	{
		return first.x < second.x;
	}
};

inline int area( point& p1,point& p2,point& p3 )
{
	return p1.x*p2.y+p3.x*p1.y+p2.x*p3.y-p3.x*p2.y-p2.x*p1.y-p1.x*p3.y;	
}
inline double dist(point& a,point& b)
{
	return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}


double __surround(point& left, point& right,vector<point>& vec)
{
	size_t i;
	int max_area = 0;
	int current_area;
	int max_idx = -1;
	vector<point> up,down;
	if( vec.size() == 0 )
		return dist(left,right);
	for( i = 0; i < vec.size(); i++ )		
	{
		if( (current_area = abs(area(left,right,vec[i]))) > max_area )
		{
			max_area = current_area;	
			max_idx = i;
		}
	}
	for( i = 0; i < vec.size(); i++ )
	{
		if(  area(left,vec[max_idx],vec[i]) > 0 )
			up.push_back(vec[i]);
		if( area(vec[max_idx],right,vec[i]) > 0 )
			down.push_back(vec[i]);
	}
	return __surround(left,vec[max_idx],up)+__surround(vec[max_idx],right,down);	
}

double surround(point* tree, int n )
{
	int i,a;
	vector<point> up,down;
	sort(tree,tree+n,sort_t());
	for( i = 1; i < n-1; i++ )
	{
		if( (a  = area(tree[0],tree[n-1],tree[i])) > 0 )	
			up.push_back(tree[i]);
		if( a < 0 )
			down.push_back(tree[i]);
	}
	return __surround(tree[0],tree[n-1],up)+__surround(tree[n-1],tree[0],down);
}
int main()
{
	int i,n;
	while(scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )
			scanf("%d%d",&tree[i].x,&tree[i].y);
		printf("%0.2lf\n",surround(tree,n));
	}
	return 0;
}
