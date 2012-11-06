#include<cstdio>
#include<algorithm>
using namespace std;
#define ROOM_CNT 201
int room[ROOM_CNT];

int main()
{
	int test_case;	
	int n,i,j,k,start,end,timeval;
	scanf("%d",&test_case);
	for( k = 0; k < test_case; k++ )
	{
		scanf("%d",&n);
		memset(room,0,sizeof(room));
		for( i = timeval = 0; i < n; i++ )
		{
			scanf("%d%d",&start,&end);
			if( start > end )
				swap(start,end);
			for( j = (start+1)/2; j <= (end+1)/2; j++ )	
			{
				room[j] += 1;
				timeval = max(room[j],timeval);
			}
		}
		printf("%d0\n",timeval);
	}
	return 0;
}
