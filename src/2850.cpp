#include<cstdio>
#define SIZE 11

int map[SIZE][SIZE];

bool do_test( int x, int y)
{
	for( int i = 0; i < x; i++ )		
	for( int j = 0; j < y; j++ )
	{
		if( map[i][j] == 0 && i + 1 < x && map[i+1][j] == 0 )	
			return false;
		if( map[i][j] == 0 && j + 1 < y && map[i][j+1] == 0 )
			return false;
	}
	return true;
}
int main()
{
	int x,y;	
	bool flag;
	while( scanf("%d%d",&x,&y) && ( x != 0 && y != 0))
	{
		flag = false;
		for( int i = 0; i < x; i++ )
		for( int j = 0; j < y; j++ )
		{
			scanf("%d",&map[i][j]);
			if( map[i][j] == 0 )
				flag = true;
		}
		if( flag == false )	
			goto done;	
		flag = do_test(x,y);		
		done:
		if( flag == false )
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
