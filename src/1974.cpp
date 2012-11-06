#include<cstdio>
#include<cmath>
using namespace std;
#define POINT_CNT 256
double x[POINT_CNT];
double y[POINT_CNT];
double a[POINT_CNT];
double b[POINT_CNT];

void solve( double x[], double a[],int n )
{
	int i;
	int flag = 1;	
	double sum = 0;
	for( i = 0; i < n-1; i++ )
	{
		sum += 2*x[i]*flag;	
		flag = -flag;
	}
	a[0] = (sum+2*x[n-1])/2;
	a[n-1] = (2*x[n-1]-sum)/2;
	for( i = 0; i < n-1; i++ )
		a[i+1] = 2*x[i]-a[i];
}
int main()
{
	int i,n;
	while( scanf("%d",&n) != -1 )
	{
		for( i = 0; i < n; i++ )
			scanf("%lf%lf",&x[i],&y[i]);
		solve(x,a,n);
		solve(y,b,n);
		printf("%d",n);
		for( i = 0; i < n; i++ )
			printf(" %0.6lf %0.6lf",a[i],b[i]);
		printf("\n");
	}
	return 0;
}
