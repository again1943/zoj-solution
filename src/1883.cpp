#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define DIGIT_LEN 10
#define NUMBE_LEN 101
double matrix[NUMBE_LEN][DIGIT_LEN];

double cal(int n, int k)
{
	int i,j;
	double ret = 0.0;
	memset(matrix,0,sizeof(matrix));
	for( i = 0; i <= k; i++ )
		matrix[1][i] = 1;
	for( i = 2; i <= n; i++ )
	for( j = 0; j <= k; j++ )
	{
		matrix[i][j] = matrix[i-1][j];
		if( j+1 <= k )
			matrix[i][j] += matrix[i-1][j+1];
		if( j-1 >= 0 )
			matrix[i][j] += matrix[i-1][j-1];
	}
	for( j = 0; j <= k; j++ )
		ret += matrix[n][j];
	for( j = 0; j < n; j++ )
		ret /= (k+1);
	return ret;
}
int main()
{
	int k,n;
	while( scanf("%d%d",&k,&n) != -1 )
		printf("%0.5lf\n",cal(n,k)*100);
	return 0;
}
