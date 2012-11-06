#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define COIN_SIZE 1001
#define MINIT 60

bool table[MINIT];
int do_work( int start, int type )
{
	int step = 0;
	memset(	table,0,sizeof(table));
	if( start > 0 )
	{
		while( 1 )
		{
			start = (start*(type+1))%60;
			step++;
			if( start == 0 )
				break;
			if( table[start] == true )
			{
				step = -1;
				break;
			}
			table[start] = true;
		}
	}
	return step;
}
int main()
{
	int start,type,ret;
	while( scanf("%d%d",&start,&type) && (type != 0||start != 0))
	{
		if((ret = do_work(start,type)) < 0 )
			printf("Impossible\n");
		else
			printf("%d\n",ret);
	}
	return 0;
}
