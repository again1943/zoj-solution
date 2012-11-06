#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define GRID_SIZE 100 
int dir[GRID_SIZE][GRID_SIZE];
double prev[GRID_SIZE][GRID_SIZE];
double next[GRID_SIZE][GRID_SIZE];
void do_first( int n )
{
	dir[0][0] = dir[0][n-1] = dir[n-1][0] = dir[n-1][n-1] = 2;		
	for( int i = 1; i < n-1; i++ )
	{
		dir[0][i] = dir[i][0] = dir[n-1][i] =dir[i][n-1] = 3;
		for( int j = 1; j < n-1; j++ )
			dir[i][j] = 4;
	}
}

double girl( int N )
{
	int i,j,k;
	double result = 0;
	double (*p)[GRID_SIZE] = prev;
	double (*n)[GRID_SIZE] = next;
	do_first(N);
	memset(prev,0,sizeof(prev));
	p[N/2][N/2] = 1.0;
	for( i = 0; i < N; i++ )
	{
		for( j = 0; j < N; j++ )		
		for( k = 0; k < N; k++ )
		{
			n[j][k] = 0.00;
			if( j > 0 )	
				n[j][k] += p[j-1][k]/dir[j-1][k];
			if( k > 0 )
				n[j][k] += p[j][k-1]/dir[j][k-1];
			if( j < N-1 )
				n[j][k] += p[j+1][k]/dir[j+1][k];
			if( k < N-1 )
				n[j][k] += p[j][k+1]/dir[j][k+1];	
		}
		result += n[i][N/2];
		n[i][N/2] = 0.00;
		swap(n,p);
	}
	return result;
}
int main()
{
	int n;
	while(scanf("%d",&n) != -1)
		printf("%0.4lf\n",girl(n));
	return 0;
}
