#include <cstdio>
#include <cstring>
#include <limits>
#include <algorithm>

using namespace std;

#define MAX_NUM 1000
#define MAX_STR 10000

int bankers[MAX_NUM];
int bonus[MAX_STR][100];
int trace[MAX_STR][100];
char result[MAX_STR];
int main()
{
	int n,m,x,y,k,t,i;	
	while( scanf("%d%d",&n,&m) != -1 )
	{
		for( i = 0; i < MAX_STR; i++ )
			for( t = 0; t < 100; t++ )
				bonus[i][t] = numeric_limits<int>::min();
		memset(bankers,0,sizeof(bankers));
		memset(trace,-1,sizeof(trace));

		for( i = 0; i < n; i++ )		
		{
			scanf("%d%d",&x,&y);
			bankers[x] = y;
		}
		for( i = 0; i < MAX_NUM; i++ )
		{
			x = i/10;
			if( bonus[m-3][x] < bankers[i] )
			{
				bonus[m-3][x] = bankers[i];
				trace[m-3][x] = i;
			}
		}
		for( i = m-4; i >= 0; i-- )
			for( k = 0; k < 100; k++ )
				for( t = 0; t < 10; t++ )	
				{
					x = k+t*100;
					if(  bonus[i][x/10] < bonus[i+1][k]+bankers[x] )
					{
						bonus[i][x/10] = bonus[i+1][k]+bankers[x];
						trace[i][x/10] = k;
					}
				}
				for( t = 0,i = 1; i < 100; i++ )
				{
					if( bonus[0][i] > bonus[0][t] )
						t = i;
				}
				for( i = 0; i <= m-3; i++ )
				{
					result[i] = t/10+'0';		
					t = trace[i][t];
				}
				result[m-3] = t/100+'0';
				t %= 100;
				result[m-2] = t/10+'0';
				t %= 10;
				result[m-1] = t+'0';
				result[m] = 0;
				printf("%s\n",result);
	}
	return 0;
}
