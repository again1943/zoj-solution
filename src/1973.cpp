#include<cstdio>
using namespace std;
int main()
{
	double firstx,firsty;
	double lastx,lasty;
	double thisx,thisy;
	int n,i;
	while( scanf("%d",&n) != -1 )
	{
		scanf("%lf%lf",&firstx,&firsty);
		lastx = firstx;
		lasty = firsty;
		printf("%d",n);
		for( i = 1; i < n; i++ )
		{
			scanf("%lf%lf",&thisx,&thisy);
			printf(" %0.6lf %0.6lf",(thisx+lastx)/2,(thisy+lasty)/2);
			lastx = thisx;
			lasty = thisy;
		}
		printf(" %0.6lf %0.6lf\n",(lastx+firstx)/2,(lasty+firsty)/2);
	}
	return 0;
}
