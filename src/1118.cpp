#include<cstdio>
#include<utility>
#include<string>
#include<map>
#include<bitset>
#include<vector>
using namespace std;
#define MAX_DIMENSION 10
#define MAX_POTIONS 100



int start[MAX_DIMENSION];
int end[MAX_DIMENSION];

map<string,int>key_map;
vector<bitset<MAX_DIMENSION> >G(MAX_DIMENSION);

void ret_set()
{	
	int i;
	key_map.clear();
	for( i = 0; i < MAX_DIMENSION; i++ )
		G[i].reset();	
}

int get_index( map<string,int>&key_map, string& point ,int& index )
{
	int ret = -1;
	map<string,int>::iterator pos;
	if( (pos = key_map.find(point)) != key_map.end())
		ret = pos->second;
	else
	{
		ret = index;
		key_map.insert(make_pair(point,index++));
	}
	return ret;
}

bool dfs( int start, int end,int n )
{
	int i = 0;
	bool ret;
	if( start == end )		
		return true;
	for( i = 0; i < n; i++ )
	{
		if( i != start && G[start][i] == true )	
		{
			G[start][i] = G[i][start] = false;	
			if( (ret = dfs(i,end,n)) == true )
				return true;
			G[start][i] = G[i][start] = true;
		}
	}
	return false;
}
int main()
{
	int n,c,i;
	int t = 0;
	int start,end,index,from,to;
	string point;
	while( scanf("%d",&n ) && n != 0 )
	{
		index = 0;
		for( i = 0; i < n; i++ )	
		{
			scanf("%d",&c);	
			point.push_back(c+'0');	
		}
		start = get_index(key_map,point,index);
		point.clear();

		for( i = 0; i < n; i++ )	
		{
			scanf("%d",&c);	
			point.push_back(c+'0');	
		}
		end = get_index(key_map,point,index);
		point.clear();
		
		while( scanf("%d",&c) && c != -1 )
		{
			point.push_back(c+'0');
			for( i = 1; i < n; i++ )	
			{
				scanf("%d",&c);
				point.push_back(c+'0');
			}
			from = get_index(key_map,point,index);			
			point.clear();
			for( i = 0; i < n; i++ )
			{
				scanf("%d",&c);
				point.push_back(c+'0');
			}
			to = get_index(key_map,point,index);
			point.clear();
			G[from][to] = true;
			G[to][from] = true;
		}
		printf("Maze #%d can%s be travelled\n",++t,(dfs(start,end,index)?"":"not"));
		ret_set();
	}
	return 0;
}
