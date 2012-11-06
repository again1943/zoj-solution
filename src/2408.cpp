#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX_N 14
#define LIMIE 1e-8

double poly[MAX_N];

double eval( double* poly, double x,int n )
{
	double val = 0;	
	for( int i = 1; i < n; i++ )
		val += val*x+poly[i];
	return val;
}

inline int zero( double val )
{
	if( fabs(val) < LIMIE )		
		return 0;
	return val >= LIMIE?1:-1;
}

double bin( double* poly, int n )
{
	int temp;
	double x = 0;
	double y = 1;
	double m,fx,fy,fm;
	fx = eval(poly,x,n);	
	fy = eval(poly,y,n);
	if( zero( fx ) == 0 )
		return x;
	if( zero( fy ) == 0 )
		return y;
	while( 1 )
	{
		m = (x+y)/2;
		fm = eval(poly,m,n);
		if( (temp = zero(fm)) == 0 )
			return m;
		else if( temp* zero(fx) < 0 )
		{
			y = m;	
			fy = eval(poly,y,n);
		}
		else
		{
			x = m;
			fx = eval(poly,x,n);
		}
	}
}

int main()
{
	int t = 0;
	int i,n,last,p;	
	double total;
	while( scanf("%d",&n) && n >= 0 )
	{
		if( t++ )
			printf("\n");
		memset(poly,0,sizeof(poly));
		for( i = 0; i < n; i++ )
		{
			scanf("%d",&p);
			scanf("%lf",&poly[p]);
		}
		scanf("%d%lf",&last,&total);
		for( i = 0; i < last; i++ )
			poly[last+1] = -total;
		printf("Case %d: %0.5lf\n",t,bin(poly,last+2));
	}
	return 0;
}
