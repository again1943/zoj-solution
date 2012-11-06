#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#define MAXID 10008

int player[MAXID];

int findsec( int* p, int n, int maxval )
{
	int i;
	for( i = 0; i <= n; i++ )
		if( p[i] == maxval )
			p[i] = 0;
	for(i = maxval = 0; i <= n; i++ )
		maxval = std::max(maxval,p[i]);
	return maxval;
}
int main()
{
	int n,m,i,j,id,maxval,maxid;
	while( scanf("%d%d",&n,&m) && n != 0)
	{
		maxval = maxid = 0;
		memset(player,0,sizeof(player));
		for( i = 0; i < n; i++ )
		for( j = 0; j < m; j++ )
		{
			scanf("%d",&id);
			player[id]++;
			maxid = std::max(maxid,id);
			maxval = std::max(maxval,player[id]);
		}
		maxval = findsec(player+1,maxid,maxval);
		for( i = 1; i <= maxid; i++ )
			if( player[i] == maxval )
				printf("%d ",i);
		printf("\n");
	}
	return 0;
}