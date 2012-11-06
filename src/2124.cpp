#include<math.h>
#include<stdio.h>
double esp = 1e-12;
int main()
{
	int i;
	double num;
	double temp;
	double result;
	scanf("%lf",&num);
	while( fabs(num) > 1  )
	{
		if( num > 0 )
		{		
			for( i = 32; i >= 1; i-- )
			{
				temp = pow( num,1/((double)i));
				result = nearbyint( temp );//find the nearest integer to temp
				if( fabs( temp-result ) < esp )
				{
					printf("%d\n",i);
					break;
				}
			}
		}
		else
		{
			num = -num;
			for( i = 31; i >= 1; i -= 2 )
			{
				temp = pow( num,1/((double)i));
				result = nearbyint( temp );
				if( fabs(  temp-result) < esp )
				{
					printf("%d\n",i);
					break;
				}
			}
		}
		scanf("%lf",&num);
	}
	return 0;
}
