#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define MAX_SIZE 128

double prev[MAX_SIZE];
double next[MAX_SIZE];
int neighbor[MAX_SIZE];
int matrix[MAX_SIZE][MAX_SIZE];

void transform(double* a, double* b, int n)
{
	int i,j;	
	for( i = 0; i < n; i++ )		
	{
		b[i] = 0;
		if( neighbor[i] == 0 )
		{
			b[i] = a[i];
			continue;
		}
		for( j = 0; j < n; j++ ) 
		{
			if( matrix[i][j] != 0 )
				b[i] += a[j]/neighbor[j];
		}
	}
}
inline bool same( double* a, double* b,int n )
{
#define esp 1e-4	
	int i;
	for( i = 0; i < n; i++ )
		if( fabs(a[i]-b[i]) > esp )
			return false;
	return true;
}
int main()
{
	double *a,*b;
	int t,k,n,m,i,x,y;	
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d%d",&n,&m);	
		for( i = 0; i < n; i++ )
			scanf("%lf",&prev[i]);
		memset(neighbor,0,sizeof(neighbor));
		memset(matrix,0,sizeof(matrix));
		for( i = 0; i < m; i++ )
		{
			scanf("%d%d",&x,&y);
			neighbor[x-1] += 1;
			neighbor[y-1] += 1;
			matrix[x-1][y-1] = matrix[y-1][x-1] = 1;
		}
		a = prev;
		b = next;
		transform(a,b,n);
		while( same(a,b,n) != true )
		{
			std::swap(a,b);	
			transform(a,b,n);
		}
		for( i = 0; i < n; i++ )
			printf("%0.3lf\n",prev[i]);
		printf("\n");
	}
	return 0;
}
