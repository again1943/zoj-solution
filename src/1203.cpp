#include<cmath>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

#define CITY_SIZE 101

struct point_t
{
	double x;
	double y;
};

class disjoint_set
{
	int size_;		
	int* elem_;
	int max_set_;
public:
	disjoint_set()
	{
		size_ = 0;
		elem_ = 0;
		max_set_ = -1;
	}
	~disjoint_set()
	{
		if( elem_ != 0 )
			delete[] elem_;
	}
	int size()
	{
		return size_;
	}
	int max_set()
	{
		return max_set_;
	}
	int max_set_size()
	{
		return -elem_[max_set_];
	}
	void make_set(int n)
	{
		size_ = n;
		elem_ = new int[size_];
		fill(elem_,elem_+size_,-1);
		max_set_ = 0;
	}
	int find_set(int n)
	{
		int x = n;

		int idx = 0;
		int* stk = new int[size_];
		while( elem_[x] >= 0 )
		{
			stk[idx++] = x;
			x = elem_[x];
		}
		
		for( int i = 0; i < idx; i++ )
			elem_[stk[i]] = x;
		delete[] stk;

		return x;
	}
	bool same_set(int x, int y)
	{
		return (find_set(x) == find_set(y));	
	}
	void union_set(int x,int y)
	{
		int change;
		int root_x = find_set(x);
		int root_y = find_set(y);

		if( root_x != root_y )
		{
			if( elem_[root_x] <= elem_[root_y])	
			{
				elem_[root_x] += elem_[root_y];	
				elem_[root_y] = root_x;
				change = root_x;
			}
			else
			{
				elem_[root_y] += elem_[root_x];	
				elem_[root_x] = root_y;
				change = root_y;
			}
			max_set_ = (elem_[change] < elem_[max_set_])?change:max_set_;
		}
	}
};

struct elem_t
{
	int first;
	int second;
	double len;
	elem_t()
	{
		first = second = 0;
		len = 0.00;		
	}
	elem_t(int x, int y, double len_)
	{
		first = x;
		second = y;
		len = len_;
	}
};

struct comp_t
{
	bool operator()(const elem_t& x, const elem_t& y)
	{
		return x.len > y.len;	
	}
};

inline double point_dist( const point_t& first,const point_t& second)
{
	return sqrt((first.x-second.x)*(first.x-second.x)+
		(first.y-second.y)*(first.y-second.y));
}

point_t city[CITY_SIZE];

double MSP(int n)
{
	double total_len = 0.00;
	elem_t temp;
	disjoint_set dist_set;
	priority_queue< elem_t,	vector<elem_t>,comp_t > dist_queue;

	for( int i = 0; i < n; i++ )
	for( int j = i+1; j < n; j++ )
	{
	#ifdef DEBUG
		double ds = point_dist(city[i],city[j]);
		printf("Disttance of (%0.2lf,%0.2lf) and (%0.2lf,%0.2lf) is %0.2lf\n",
			city[i].x,city[i].y,city[j].x,city[j].y,ds);
	#endif
		dist_queue.push(elem_t(i,j,point_dist(city[i],city[j])));
	}
	dist_set.make_set(n);
	while( dist_set.max_set_size() != n )
	{
		temp = dist_queue.top();
		dist_queue.pop();
		if(dist_set.find_set(temp.first) != dist_set.find_set(temp.second))
		{
			total_len += temp.len;		
			dist_set.union_set(temp.first,temp.second);
		}
	}
	return total_len;
}
int main()
{
	int n;
	int count = 0;
	double length;
	while(scanf("%d",&n) && n != 0)
	{
		if( count > 0 )
			printf("\n");
		for( int i = 0; i < n; i++ )
			scanf("%lf%lf",&city[i].x,&city[i].y);
		if(  n == 1 )
			length = 0.00;	
		else
			length = MSP(n);
		printf("Case #%d:\nThe minimal distance is: %0.2lf\n",++count,length);
	}
	return 0;
}
