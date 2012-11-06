#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define SIZE 10001

struct rect_t
{
	int min_x,min_y,max_x,max_y;
}rect[SIZE];

bool sure[SIZE];

bool inside( rect_t& a, rect_t& b )
{
	return (a.min_x >= b.min_x && a.min_y >= b.min_y &&
		a.max_x <= b.max_x && a.max_y <= b.max_y);
}

int main()
{
	int i,j,n,c;
	while(scanf("%d",&n) != -1)
	{
		c = 0;
		for(i = 0; i < n; i++ )
			scanf("%d%d%d%d",&rect[i].min_x,&rect[i].max_x,
				&rect[i].min_y,&rect[i].max_y);
		memset(sure,0,sizeof(sure));
		for( i = 0; i < n; i++ )
		{
			if( sure[i] == false )
			{
				for( j = i+1; j < n; j++ )
				{
					if( inside(rect[j],rect[i]) == true )
					{
						c++;
						sure[j] = true;
					}
					if( inside(rect[i],rect[j]) == true )
					{
						c++;
						break;
					}
				}
				sure[i] = true;
			}
		}
		printf("%d\n",c);
	}
	return 0;
}

