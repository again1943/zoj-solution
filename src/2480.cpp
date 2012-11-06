#include<cstdio>
using namespace std;

#define WINDOW_CNT 16
struct point_t
{
	int x,y;	
};
struct window_t
{
	point_t upper_left,lower_right;
}windows[WINDOW_CNT];

bool inside( point_t& p, point_t& upper_left, point_t& lower_right )
{
	return (p.x >= upper_left.x && p.x <= lower_right.x 
		&&p.y >= upper_left.y && p.y <= lower_right.y);
}
int find_window( window_t* window, int n, point_t& p )
{
	int i;
	for( i = n-1; i >= 0; i-- )
		if( inside(p,window[i].upper_left,window[i].lower_right))
			return i;
	return -1;
}
int main()
{
	point_t p;
	int i,n,click;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )		
			scanf("%d%d%d%d",
			&windows[i].upper_left.x,
			&windows[i].upper_left.y,
			&windows[i].lower_right.x,
			&windows[i].lower_right.y);
		scanf("%d",&click);
		for( i = 0; i < click; i++ )
		{
			scanf("%d%d",&p.x,&p.y);	
			printf("%d\n",find_window(windows,n,p));
		}
	}
	return 0;
}
