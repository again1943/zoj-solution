#include<cstdio>
#include<cmath>
using namespace std;

#define MAX_ITER 100
#define EPS 1e-8
#define PI 3.1415926

inline double func( double etha,double l,double d )
{
	return  (etha*cos(etha)-sin(etha))/(cos(etha)-d/l);
}

double detail(double d,double n,double c)
{
	int i = 0;
	double l = (1+n*c)*d;	
	double p0 = PI/4;
	double p;
	while( i < MAX_ITER )
	{
		p = func(p0,l,d);
		if( fabs(p-p0) < EPS )
			return p;
		i += 1;
		p0 = p;
	}
	return -1;
}
int main()
{
	int d,n;
	double c,etha;		
	while( scanf("%d%d%lf",&d,&n,&c) && d >= 0 )
	{
		if(  d == 0 || n == 0 || c < EPS )
			printf("0.000\n");
		else
		{
			etha = detail(d,n,c);
			printf("%0.3lf\n",d*(1/sin(etha)-1/tan(etha))/2);
		}
	}
	return 0;
}
