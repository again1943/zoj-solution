#include<cstdio>
using namespace std;
int main()
{
	double mw,mi,tw,ti;
	double left,water,ice,temperature;
	while( scanf("%lf%lf%lf%lf",&mw,&mi,&tw,&ti) && 
		(mw > 0||mi > 0 ||tw >0 || ti >0 ))
	{
		if( (left = 4.19*mw*tw+2.09*mi*ti-335*mi) >= 0 )
		{
			water = mw+mi;	
			ice = 0;
			temperature = left/(water*4.19);
		}
		else if( (left = 4.19*mw*tw+335*mw+2.09*mi*ti) <= 0 )
		{
			ice = mw+mi;			
			water = 0;
			temperature = left/(ice*2.09);
		}
		else if( (left = 4.19*mw*tw+2.09*mi*ti) != 0 )
		{
			temperature = 0;
			water = mw + left/335;
			ice = mi-left/335;
		}
		else
		{
			water = mw;	
			ice = mi;
			temperature = 0;
		}
		printf("%0.1lf g of ice and %0.1lf g of water at %0.1lf C\n",ice,water,temperature);
	}
	return 0;
}
