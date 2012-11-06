#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

#define MAXN 1024
bool ok[MAXN][MAXN];
char way[MAXN][MAXN];
size_t mxh[MAXN][MAXN];
int height[MAXN];
char result[MAXN];

int dp(int* h,size_t n, size_t sum,char* result)
{
	size_t i,j,v;
	memset(ok,false,sizeof(ok));
	memset(way,0,sizeof(way));
	memset(result,0,sizeof(result));
	memset(mxh,1,sizeof(mxh));

	ok[0][h[0]] = true;
	mxh[0][h[0]] = h[0];
	way[0][h[0]] = 'U';
	for( i = 1; i < n; i++ )
	for( j = 0; j <= sum; j++ )
	{
		if( ok[i-1][j] == true )	
		{
			if( j-h[i] >= 0 )
			{
				v = max(j,mxh[i-1][j]);
				if( v < mxh[i][j-h[i]] )
				{
					ok[i][j-h[i]] = true;
					mxh[i][j-h[i]] = v;
					way[i][j-h[i]] = 'D';
				}
			}
			if( j+h[i] <= sum )
			{
				v = max(j+h[i],mxh[i-1][j]);	
				if( v < mxh[i][j+h[i]] )
				{
					ok[i][j+h[i]] = true;
					mxh[i][j+h[i]] = v;
					way[i][j+h[i]] = 'U';
				}
			}
		}
	}
	if( ok[n-1][0] != true )
		return -1;
	int x = n-1;
	int y = 0;
	int c = 0;
	while( way[x][y] == 'U' || way[x][y] == 'D' )
	{
		result[c++] = way[x][y];
		if( way[x][y] == 'U' )
			y -= h[x];
		else
			y += h[x];
		x -= 1;
	}
	result[c] = 0;
	reverse(result,result+c);
	return 1;
}

int main()
{
	int t,k,n,i,sum,ret;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d",&n);
		for( i = sum = 0; i < n; i++ )
		{
			scanf("%d",&height[i]);	
			sum += height[i];
		}
		if( (ret = dp(height,n,sum,result)) < 0 )
			printf("IMPOSSIBLE\n");
		else
			printf("%s\n",result);
	}
	return 0;
}