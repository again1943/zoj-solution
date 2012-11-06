#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 256
#define INF 123478900
int points[MAXN][2];
double mat[MAXN][MAXN];

inline double dist( int x1,int y1, int x2, int y2 )
{
	return sqrt((double)((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

double dijkstra( double mat[][MAXN], int n,int s, int e )
{
	int i,j,k;
	bool in[MAXN];
	double val,v[MAXN];
	memset(in,0,sizeof(bool)*MAXN);
	for( i = 1; i < n; i++ )
		v[i] = INF;
	v[s] = 0;

	while( 1 )
	{
		for( i = 0,k = -1,val = INF; i < n; i++ )	
		{
			if( in[i] != true && val > v[i] )	
			{
				k = i;
				val = v[i];
			}
		}
		if( k == -1 )
			break;
		in[k] = true;
		for( i = 0; i < n; i++ )
		{
			if( in[i] != true )
			{
				val = max(v[k],mat[k][i]);
				v[i] = min(max(v[k],mat[k][i]),v[i]);
			}
		}
	}
	return v[e];
}

int main()
{
	int n,i,j;
	int t = 0;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )	
		{
			scanf("%d%d",&points[i][0],&points[i][1]);
			for( j = i-1; j >= 0; j-- )
				mat[i][j] = mat[j][i] = dist(points[i][0],
					points[i][1],points[j][0],points[j][1]);
		}
		printf("Scenario #%d\nFrog Distance = %0.3lf\n\n",
		(t++)+1,dijkstra(mat,n,0,1));
	}
	return 0;
}
