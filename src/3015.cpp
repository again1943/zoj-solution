#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

#define PI  3.141592653589793239
int main()
{
	double h,k,a,b,x,y,z,e;
	while(scanf("%lf%lf%lf%lf",&k,&h,&a,&b) != -1)
	{
		e = k*PI/180;
		z = h*cos(e)-b*sin(e);
		x = a*a+b*b+4*cos(e)*(h-a)*z;
		printf("%0.2lf\n",sqrt(x));
	}
	return 0;
}