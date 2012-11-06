#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXN 12
struct point_t
{
	double x,y;
};
struct sort_t
{
	bool operator()(const point_t& a, const point_t& b )
	{
		return a.x < b.x;
	}
};

point_t coordinate[2][MAXN];

point_t other(point_t& a, point_t& b )
{
	point_t retval;
	double etha = atan((b.y-a.y)/(b.x-a.x))+
	acos(sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y))/4);
	retval.x = a.x+2*cos(etha);
	retval.y = a.y+2*sin(etha);
	return retval;

}
point_t detail( point_t place[][MAXN], int n )
{
	int i;
	point_t* item;
	point_t* x = place[0];
	point_t* y = place[1];
	while( n != 1 )
	{
		for( i = 0; i < n-1; i++ )
			y[i] = other(x[i],x[i+1]);	
		item = x;
		x = y;
		y = item;
		n -= 1;
	}
	return x[0];
}
int main()
{
	int n,i;
	point_t retval;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )
		{
			scanf("%lf",&coordinate[0][i].x);
			coordinate[0][i].y = 1;
		}
		sort(coordinate[0],coordinate[0]+n,sort_t());
		retval = detail(coordinate,n);
		printf("%0.4lf %0.4lf\n",retval.x,retval.y);
	}
	return 0;
}
