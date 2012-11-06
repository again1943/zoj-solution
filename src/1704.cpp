#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
#define POINT_CNT 16
struct point_t
{
	char name;
	int x,y;
}points[POINT_CNT];
inline int area(point_t& a,point_t& b,point_t& c)
{
	return abs(((c.y-a.y)*(b.x-a.x)-(b.y-a.y)*(c.x-a.x)));
}

bool test_ok(point_t* points, int n, int a, int b, int c )
{
	int i;
	for( i = 0; i < n; i++ )
	{
		if( i == a || i == b || i == c )
			continue;
		if( area(points[a],points[b],points[i]) + 
			area(points[b],points[c],points[i])+
			area(points[c],points[a],points[i]) ==
			area(points[a],points[b],points[c]))	
			return false;		
	}
	return true;
}
void do_work( point_t* points, int n, int& a,int& b, int& c)
{
	int i,j,k,temp;
	int max_area = 0;
	for( i = 0; i < n; i++ )
	for( j = i+1; j < n; j++ )
	for( k = j+1; k < n; k++ )
	{
		if( test_ok(points,n,i,j,k) && (temp = area(points[i],points[j],points[k])) > max_area)
		{
			a = i;
			b = j;
			c = k;
			max_area = temp;
		}
	}
}
int main()
{
	int i,n;
	int a,b,c;
	while( scanf("%d",&n) && n != 0 )
	{
		getchar();
		for( i = 0; i < n; i++ )
		{
			scanf("%c%d%d",&points[i].name,&points[i].x,&points[i].y);
			getchar();
		}
		do_work(points,n,a,b,c);
		printf("%c%c%c\n",points[a].name,points[b].name,points[c].name);
	}
	return 0;
}
