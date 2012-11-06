#include <cmath>
#include <cstdio>


inline double distance(long long x1, long long y1, long long x2,long long y2)
{
	long long value = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	return sqrt((double)(value));
}
void bisec_point(long long* x, long long* y, double& px, double& py)
{
	double line[3];	
	line[0] = distance(x[1],y[1],x[2],y[2]);		
	line[1] = distance(x[0],y[0],x[2],y[2]);
	line[2] = distance(x[0],y[0],x[1],y[1]);

	px = (line[0]*x[0]+line[1]*x[1]+line[2]*x[2])/(line[0]+line[1]+line[2]);
	py = (line[0]*y[0]+line[1]*y[1]+line[2]*y[2])/(line[0]+line[1]+line[2]);
}
int main()
{
	double px,py;
	long long x[3],y[3],n,i;
	scanf("%lld",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%lld,%lld%lld,%lld%lld,%lld",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
		bisec_point(x,y,px,py);
		px = (double)((long long)(px*10000))/10000.00;
		py = (double)((long long)(py*10000))/10000.00;
		printf("(%lld,%lld)(%lld,%lld)(%lld,%lld):(%0.4lf,%0.4lf)\n",x[0],y[0],x[1],y[1],x[2],y[2],px,py);
	}
	return 0;
}
