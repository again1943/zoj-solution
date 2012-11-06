#include<cmath>
#include<cstdio>

using namespace std;

inline double function( double x,double a )
{
//	return (log(x)-1)/(log(a)/a-1/x);	
	return x-(x*log(a)-a*log(x))/(log(a)-a/x);
}

double Newton( double x )
{
	double y = 100.0 ;
	double a = x;
	
	x = function(y,a);	
	while( fabs( x-y ) > 1e-7 )
	{
		y = x;
		x = function(y,a);
	}
	
	return x;			
}

int main()
{
	double x;
	double y;
	double e = 2.718281;
	while( scanf("%lf",&x) != -1 )
	{
		if( x < e )
		{
			y = Newton(x);	
			printf("%0.5lf\n",y);
		}
		else
			printf("-1\n");
	}
	return 0;
}

