#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX_POINT 20004

struct point_t
{
	int x,y;
};

struct sort_t
{
	bool operator()( const point_t& a, const point_t& b )
	{
		if( a.x != b.x )
			return a.x > b.x;
		return a.y > b.y;
	}
};

point_t points[MAX_POINT];


int main()
{
	int n,i;	
	point_t center;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )
			scanf("%d%d",&points[i].x,&points[i].y);	
		sort(points,points+n,sort_t());
		center.x = points[0].x+points[n-1].x;
		center.y = points[0].y+points[n-1].y;
		for( i = 1; i <= n/2; i++ )
		{
			if( center.x != points[i].x+points[n-i-1].x ||
				center.y != points[i].y+points[n-i-1].y )
				break;
		}
		if( i > n/2 )
			printf("V.I.P. should stay at (%0.1lf,%0.1lf).\n",
			center.x/2.0,center.y/2.0);
		else
			printf("This is a dangerous situation!\n");
	}
	return 0;
}


