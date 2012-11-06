#include<cstdio>
#include<cstdio>
#include<bitset>
#include<vector>
#include<algorithm>
using namespace std;
#define BIT_SIZE 6

typedef vector<bitset<BIT_SIZE> > MAP;

char map[BIT_SIZE][BIT_SIZE];

int bfs( MAP& bit_map,int row,int col,int n )
{
	int ret,i,j;
	int max_ = 0;
	if( row < n )
	{
		MAP map_copy;
		
		for( i = col; i < n; i++ )	
		{		
			ret = 0;
			map_copy = bit_map;	
			if( map_copy[row][i] == true )	
			{
				ret += 1;
				map_copy[row][i] = false;
				for( j = i+1; j < n && map[row][j] != 'X'; j++ )
					map_copy[row][j] = false;
				for( j = i-1; j >= 0 && map[row][j] != 'X'; j-- )
					map_copy[row][j] = false;
				for( j = row+1; j < n && map[j][i] != 'X'; j++ )
					map_copy[j][i] = false;	
				for( j = row-1; j >= 0 && map[j][i] != 'X'; j-- )
					map_copy[j][i] = false;
				ret += bfs(map_copy,row,i+1,n);
			}
			max_ = max(max_,ret );
		}
		max_ = max(max_,bfs(bit_map,row+1,0,n));
	}
	return max_;
}

int main()
{
	int n,i,j;
	MAP bit_map(BIT_SIZE);
	while((scanf("%d",&n) && n != 0 ))
	{
		for( i = 0; i < n; i++ )
		{
			scanf("%s",map[i] );
			bit_map[i].set();
		}
		for( i = 0; i < n; i++ )
		for( j = 0; j < n; j++ )
		{
			if( map[i][j] == 'X' )
				bit_map[i][j] = false;
		}
		printf("%d\n",bfs(bit_map,0,0,n));
	}
	return 0;
}
