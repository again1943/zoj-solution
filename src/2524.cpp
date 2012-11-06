#include<cstdio>
#include<utility>
#include<cstring>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std;
#define NAME_LEN 25
#define TEAM_CNT 100010

struct team_t
{
	int w,d,l,gd;
	char name[NAME_LEN];				
}team[TEAM_CNT];

struct comp_t
{
	bool operator()(const char* first, const char* second)
	{
		return strcmp(first,second) < 0;
	}
};

struct sort_t
{
	bool operator()( const team_t& first,const team_t& second )
	{
		int x = first.w*3+first.d;	
		int y = second.w*3+second.d;
		if( x != y )
			return x > y;
		else 
		{
			if( first.gd != second.gd )
				return first.gd > second.gd;
			else
				return strcmp(first.name,second.name) < 0;
		}
	}
};

int main()
{
	int t = 0;
	int x,y,n,i,idx,tmp;
	map<char*,int,comp_t> pos_map;
	char one[NAME_LEN],two[NAME_LEN];
	map<char*,int,comp_t>::iterator pos;

	while( scanf("%d",&n) != -1 )
	{
		if( t++ != 0 )
		{
			pos_map.clear();
			printf("\n");
		}
		for( i = idx = 0; i < n; i++ )
		{
			scanf("%s%d:%d%s",one,&x,&y,two);
			if((pos = pos_map.find(one)) == pos_map.end())
			{
				strcpy(team[idx].name,one);	
				team[idx].w = x > y ? 1:0;			
				team[idx].d = x == y ? 1:0;
				team[idx].l = x < y ? 1:0;
				team[idx].gd = x-y;
				pos_map.insert(make_pair(team[idx].name,idx));
				idx += 1;
			}
			else
			{
				tmp = pos->second;
				team[tmp].w += x > y ?1:0;
				team[tmp].d += x == y ? 1:0;
				team[tmp].l += x < y?1:0;
				team[tmp].gd += x-y;
			}
			if( (pos = pos_map.find(two)) == pos_map.end())
			{
				strcpy(team[idx].name,two);	
				team[idx].w = x < y ? 1:0;			
				team[idx].d = x == y ? 1:0;
				team[idx].l = x > y ? 1:0;
				team[idx].gd = y-x;
				pos_map.insert(make_pair(team[idx].name,idx));
				idx += 1;
			}
			else
			{
				tmp = pos->second;
				team[tmp].w += x < y ?1:0;
				team[tmp].d += x == y ? 1:0;
				team[tmp].l += x > y?1:0;
				team[tmp].gd += y-x;
			}
		}
		sort(team,team+idx,sort_t());
		for( i = 0; i < idx; i++ )
			printf("%d %s %d %d %d %d %d\n",i+1,
				team[i].name,team[i].w,team[i].d,
				team[i].l,team[i].w*3+team[i].d,
				team[i].gd);
	}
	return 0;
}
