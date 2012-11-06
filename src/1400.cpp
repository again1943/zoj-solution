#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define NAME_LEN 16
#define PROBLEM_CNT 7
#define TEAM_CNT 20
struct team_t
{
	char name[NAME_LEN];
	int time[PROBLEM_CNT];
	int total_solved;
	int total_time;
	int geometric;
	int rank;	
}teams[TEAM_CNT];

struct sort_t
{
	bool operator()(const team_t& a, const team_t& b )
	{
		if( a.total_solved != b.total_solved )	
			return a.total_solved > b.total_solved;
		if( a.total_time != b.total_time )
			return a.total_time < b.total_time;
		if( a.geometric != b.geometric )	
			return a.geometric < b.geometric;
		return strcmp(a.name,b.name) < 0;
	}
};
int main()
{
	int n,i,j;
	double geome;
	int t = 0;	
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )
		{
			scanf("%s",teams[i].name);
			teams[i].total_solved = teams[i].total_time = 0;
			geome = 0;
			for( j = 0; j < 7; j++ )
			{
				scanf("%d",&teams[i].time[j]);
				teams[i].total_time += teams[i].time[j];	
				if( teams[i].time[j] != 0 )
				{
					teams[i].total_solved += 1;
					geome += log((double)teams[i].time[j]);	
				}
			}
			if( teams[i].total_solved == 0 )
				teams[i].geometric  = 0;
			else
				teams[i].geometric = (int)(exp(geome/teams[i].total_solved)+0.5);
		}
		sort(teams,teams+n,sort_t());
		printf("CONTEST %d\n",++t);
		//CONTEST 1
		//01 Plutonians 7 1992 261 123 234 345 456 167 278 389
		teams[0].rank = 1;
		printf("01 %-10s %d %4d %3d",teams[0].name,teams[0].total_solved,
				teams[0].total_time,teams[0].geometric);
		for( j = 0; j < 7; j++ )
			printf(" %3d",teams[0].time[j]);
		printf("\n");
		for( i = 1; i < n; i++ )
		{
			if( teams[i].total_solved != teams[i-1].total_solved ||
				teams[i].total_time != teams[i-1].total_time ||
				teams[i].geometric != teams[i-1].geometric )		
				teams[i].rank = i+1;
			else
				teams[i].rank = teams[i-1].rank;
			printf("%s%d %-10s %d %4d %3d",(teams[i].rank< 10?"0":""),
				teams[i].rank,teams[i].name,teams[i].total_solved,
				teams[i].total_time,teams[i].geometric);
			for( j = 0; j < 7; j++ )
				printf(" %3d",teams[i].time[j]);
			printf("\n");
		}
	}
	return 0;
}
