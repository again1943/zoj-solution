#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	int n = 0;
	int w,d,x;
	while( scanf("%d%d",&w,&d) && (w != 0 && d != 0 ))
	{
		x = (int)(5730*log((810.0*w)/d)/log(2.0));
		if( x < 10000 )
			x = ((x+50)/100)*100;
		else
			x = ((x+500)/1000)*1000;
		printf("Sample #%d\nThe approximate age is %d years.\n\n",++n,x);
	}
	return 0;
}
