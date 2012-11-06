#include<cstdio>
#include<algorithm>
using namespace std;
#define SIZE 128
#define esp 1e-8
char matrix[SIZE][SIZE];
double possible[SIZE][SIZE];
inline bool zero( double e )
{
	return (e < esp && e > -esp);
}

double column( int n, int m, int c )
{
	int i,j;
	double retval = 0;
	memset(possible,0,sizeof(possible));
	possible[0][c] = 1.0;
	for( i = 0; i < n-1; i++ )
	for( j = 0; j < m; j++ )	
	{
		if( zero(possible[i][j]) == true )
			continue;
		if( matrix[i][j] == '.' )
			possible[i+1][j] += possible[i][j];
		else if( matrix[i][j] == '*' )
		{
			possible[i+1][j-1] += possible[i][j]/2;
			possible[i+1][j+1] += possible[i][j]/2;
		}
		else
			retval += (matrix[i][j]-'0')*possible[i][j];
	}
	for( j = 0; j < m; j++ )
		if( matrix[n-1][j] > '0' && matrix[n-1][j] <= '9' && !zero(possible[n-1][j]))
			retval += possible[n-1][j]*(matrix[n-1][j]-'0');
	return retval;
}
double pachinko( int n, int m )
{
	int i;
	double maxval = 0.0;
	memset(possible,0,sizeof(possible));		
	for( i = 0; i < n; i++ )
		maxval = max(maxval,column(n,m,i));
	return maxval;
}
int main()
{
	int n,m,i,t,test_case;
	scanf("%d",&test_case);
	for( t = 0; t < test_case; t++ )
	{
		scanf("%d%d",&n,&m);
		for( i = 0; i < n; i++ )
			scanf("%s",matrix[i]);
		printf("%0.6lf\n",pachinko(n,m));
	}
	return 0;
}
