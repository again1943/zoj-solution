#include<stdio.h>

struct point_t
{
	int x;
	int y;
};

int main()
{
	struct point_t point;
	struct point_t leftmost; 
	struct point_t rightmost;
	
	scanf("%d%d",&point.x,&point.y);
	while( point.x != 0 || point.y != 0 )
	{
		
		leftmost = rightmost = point;

		scanf("%d%d",&point.x,&point.y);
		while( point.x != 0 || point.y != 0 )
		{
			leftmost.x = (leftmost.x > point.x )? point.x:leftmost.x;
			leftmost.y = (leftmost.y > point.y )? point.y:leftmost.y;
			rightmost.x = (rightmost.x < point.x )?point.x:rightmost.x;
			rightmost.y = (rightmost.y < point.y )?point.y:rightmost.y;
			scanf("%d%d",&point.x,&point.y);
		}

		printf("%d %d %d %d\n",leftmost.x,leftmost.y,rightmost.x,rightmost.y);
		scanf("%d%d",&point.x,&point.y);
	}

	return 0;

}
