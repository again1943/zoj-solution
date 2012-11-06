#include <cstdio>
#include <cstring>
#include <algorithm>

int main()
{
	char way[32];
	int result,t,j,n,next;
	while(scanf("%d",&t) != -1)
	{
		scanf("%s%d",way,&n);
		if( strcmp(way,"Faster") == 0)
		{
			scanf("%d",&result);
			for( j = 1; j < n; j++ )
			{
				scanf("%d",&next);
				result = std::min(result,next);
			}
		}
		else
		{
			scanf("%d",&result);
			for( j = 1; j < n; j++ )
			{
				scanf("%d",&next);
				result = std::max(result,next);
			}
		}
		printf("%d\n",result);
	}
	return 0;
}