#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define MAX_POINT 1024
struct point_t
{
	double x,y;
	bool operator==(const point_t& t )
	{
		return (x == t.x && y == t.y );
	}
};
struct line_t
{
	int index;
	point_t s,e;
};
line_t M[MAX_POINT];
line_t N[MAX_POINT];

inline double area( point_t& a,point_t& b, point_t& c)
{
	return a.x*b.y+c.x*a.y+b.x*c.y-c.x*b.y-b.x*a.y-a.x*c.y;	
}
bool cross( point_t& a,point_t& b, point_t& m,point_t& n )
{
	if( a == m || a == n || b == m || b == n )	
		return true;
	return (area(a,b,m)*area(a,b,n) < 0 && 	
		area(m,n,a)*area(m,n,b) < 0 );
}
int main()
{
	int n,index,i,j;
	line_t *a,*b,c;	
	int idxa,idxb;
	while( scanf("%d",&n) && n != 0 )
	{
		a = M;
		b = N;
		for( i = idxa = idxb = index = 0; i < n; i++ )
		{
			scanf("%lf%lf%lf%lf",&c.s.x,&c.s.y,&c.e.x,&c.e.y);
			c.index = ++index;	
			for( j = 0; j < idxa; j++ )
			{
				if( !cross(c.s,c.e,a[j].s,a[j].e) )	
					b[idxb++] = a[j];
			}
			b[idxb++] = c;
			idxa = idxb;
			idxb = 0;
			swap(a,b);
		}
		printf("Top sticks: %d",a[0].index);
		for( i = 1; i < idxa; i++ )
			printf(", %d",a[i].index);
		printf(".\n");
	}
	return 0;	
}
