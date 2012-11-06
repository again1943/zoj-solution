#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
#define COUNTRY_CNT 24
bool country[COUNTRY_CNT][COUNTRY_CNT];
bool country_cpy[COUNTRY_CNT][COUNTRY_CNT];
struct queue_t
{
	int point,time;
	queue_t():point(0),time(0)
	{}
	queue_t(int p,int t):point(p),time(t)
	{}
};

int bfs(int s, int e )
{
	int i;
	int time = 0;
	queue_t item;
	queue<queue_t>Q;
	Q.push(queue_t(s,time));
	memcpy(country_cpy,country,sizeof(country));
	while( Q.empty() != true )
	{
		item = Q.front();	
		Q.pop();
		if( item.point == e )			
			return item.time;
		if( item.time != time )	
			time = item.time;
		for( i = 1; i <= 20; i++ )
		{
			if( country_cpy[item.point][i] == true )
			{
				Q.push(queue_t(i,time+1));
				country_cpy[item.point][i] = country_cpy[i][item.point] = false;
			}	
		}
	}
	return -1;
}
int main()
{
	int c,n,s,e,i,idx;
	int t = 0;
	while( scanf("%d",&c) != -1 )
	{
		memset(country,0,sizeof(country));
		for( i = 0; i < c; i++ )		
		{
			scanf("%d",&n);
			country[1][n] = country[n][1] = true;
		}
		for( idx = 2; idx <= 19; idx++ ) 
		{
			scanf("%d",&c);	
			for( i = 0; i < c; i++ )
			{
				scanf("%d",&n);
				country[idx][n] = country[n][idx] = true;
			}
		}
		scanf("%d",&n);
		printf("Test Set #%d\n",++t);
		for( i = 0; i < n; i++ )
		{
			scanf("%d%d",&s,&e);
			printf("%d to %d: %d\n",s,e,bfs(s,e));
		}
		printf("\n");
	}
	return 0;
}
