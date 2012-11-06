#include<algorithm>
#include<stack>
#include<cstdio> 
#define SIZE 100002

int map[SIZE];

int find_root( int n )
{
	int i = n;
	int temp;

	std::stack<int> stack;

	while( map[i] > 0 )
	{
		stack.push(i);
		i = map[i];
	}

	while( stack.empty() != true )
	{
		temp = stack.top();
		stack.pop();
		map[temp] = i;
	}
	return i;
}

int main()
{
	char query;
	int n,m,t;
	int x,y,temp;
	int root_x,root_y;

	t = 0;
	while( scanf("%d%d",&n,&m) != -1 )
	{
		getchar();
		if( t++ != 0 )			
			printf("\n");
		printf("Case %d:\n",t);
		std::fill(map,map+n+1,-1);
		for( int i = 1; i <= m; i++ )
		{
			scanf("%c",&query);
			if( query == 'M' )
			{
				scanf("%d%d",&x,&y);
				getchar();
				if( x == y )
					continue;
				root_x = find_root(x);
				root_y = find_root(y);
				if( root_x == root_y )
					continue;
				if(map[root_x] < map[root_y])	
				{
					map[root_x] += map[root_y];
					map[root_y] = root_x;
				}
				else
				{
					map[root_y] += map[root_x];	
					map[root_x] = root_y;
				}
			#ifdef DEBUG
			for( int i = 1; i <= n; i++ )
				printf("%d-->%d\n",i,map[i]);
			#endif
			}
			else
			{
				scanf("%d",&x);
				getchar();
				printf("%d\n",-map[find_root(x)]);
			}
		}
	}
	return 0;
}

