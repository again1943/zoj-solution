#include <cstdio>
#include <cmath>
using namespace std;

#define BITS(x) (1<<(((x)-1960)/10+2))
#define pi 3.1415926
int get_factstone(int year)
{
	int n = 3;
	int j = BITS(year);
	double x = log((double)n)*(n+0.5)+0.5*log(2*pi)-n-j*log(2.0);
	while( x < 0 )
	{
		n++;
		x = log((double)n)*(n+0.5)+0.5*log(2*pi)-n-j*log(2.0);
	}
	return n-1;
}
int main()
{
	int year;
	while(scanf("%d",&year) && year != 0 )
		printf("%d\n",get_factstone(year));
	return 0;
}