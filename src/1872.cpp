#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
using namespace std;
#define POINT_SIZE 104
struct point_t
{
	double x,y;	
}point[POINT_SIZE];

struct queue_elem_t
{
	int s,e;
	double d;
	queue_elem_t()
	{
		s = e = 0;
		d = 0.0;
	}
	queue_elem_t( int st, int ed, double dis ):s(st),e(ed),d(dis)
	{}
};

struct comp_t
{
	bool operator()(const queue_elem_t& a, const queue_elem_t& b)
	{
		return a.d > b.d;
	}
};

inline double point_dist( const point_t& a, const point_t& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline int valid( const queue_elem_t& a,set<int>& use)
{
	return (use.find(a.e) == use.end())?a.e:-1;
}

double min_spanning_tree( int n )
{
	int idx,i;
	double ret = 0.000;
	set<int>use;
	queue_elem_t temp;
	priority_queue<queue_elem_t,vector<queue_elem_t>,comp_t>min_heap;
	for( i = 1; i < n; i++ )
		min_heap.push(queue_elem_t(0,i,point_dist(point[0],point[i])));
	use.insert(0);
	while( use.size() != n )
	{
		while( (idx = valid((temp = min_heap.top()),use)) < 0 )		
			 min_heap.pop();
		use.insert(idx);
		ret += temp.d;
		for( i = 0; i < n; i++ )
			if( use.find(i) == use.end())
				min_heap.push(queue_elem_t(idx,i,point_dist(point[idx],point[i])));
	}
	return ret;
}
int main()
{
	int n,i;
	while( scanf("%d",&n) != -1 )	
	{
		for( i = 0; i < n; i++ )
			scanf("%lf%lf",&point[i].x,&point[i].y);
		printf("%0.2lf\n",min_spanning_tree(n));
	}
	return 0;
}
