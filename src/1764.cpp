#include<cstdio>
using namespace std;

struct team_t
{
	int solved;
	int penalty;
	char name[15];	
};

struct team_t team[100];

int main()
{
	int n;		
	int submit;
	int time;
	int most;
	
	while( scanf("%d",&n ) != - 1 )
	{
		most = 0;

		scanf("%s",team[0].name);
		team[0].solved = team[0].penalty = 0;

		for( int i = 0; i < 4; i++ )
		{
			scanf("%d%d",&submit,&time );	
			if( time > 0 )
			{
				team[0].solved++;	
				team[0].penalty += (submit-1)*20+time;
			}
		}

		for( int i = 1; i < n; i++ )	
		{
			scanf("%s",team[i].name);	
			team[i].solved = team[i].penalty = 0;
			for( int j = 0; j < 4; j++ )
			{
				scanf("%d%d",&submit,&time );

				if(time > 0 )
				{
					team[i].solved++;	
					team[i].penalty += (submit-1)*20+time;
				}
			}

			if( team[most].solved < team[i].solved ||
					( team[most].solved == team[i].solved &&
					  team[most].penalty > team[i].penalty ))
				most = i;

		}
		printf("%s %d %d\n",team[most].name,team[most].solved,team[most].penalty );
	}

	return 0;
}
