#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define DEVICE_CNT 24
int devices[DEVICE_CNT];
bool work[DEVICE_CNT];

int main()
{
	int t = 0;
	bool blown;
	int n,m,c,i,turn;
	int amperes,total;
	while( scanf("%d%d%d",&n,&m,&c) && n != 0 )
	{
		blown = false;
		amperes = total = 0;
		memset(work,0,sizeof(work));	
		for( i = 1; i <= n; i++ )
			scanf("%d",&devices[i]);
		for( i = 0; i < m; i++ )
		{
			scanf("%d",&turn);	
			if( !blown )
			{
				total += (work[turn]?(-devices[turn]):devices[turn]);	
				work[turn] = !work[turn];		
				amperes = max(amperes,total);
				if( total > c )
					blown = true;	
			}
		}
		printf("Sequence %d\n",++t);
		if( blown )
			printf("Fuse was blown.\n");
		else
			printf("Fuse was not blown.\n"
				"Maximal power consumption was %d amperes.\n",amperes);
		printf("\n");
	}
	return 0;
}
