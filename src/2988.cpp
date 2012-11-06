#include <cstdio>
#include <cstring>
#include <cstdlib>

int main()
{
	int n,i;
	char tail[12];
	double value;
	scanf("%d",&n);
	for( i = 1; i <= n; i++ )
	{
		scanf("%lf%s",&value,tail);
		printf("%d ",i);
		if( tail[0] == 'k' && tail[1] == 'g' )
			printf("%0.4lf lb\n",value*2.2046);
		else if( tail[0] == 'l' && tail[1] == 0 )
			printf("%0.4lf g\n",value*0.2642);
		else if( tail[0] == 'g' && tail[1] == 0 )
			printf("%0.4lf l\n",value*3.7854);
		else
			printf("%0.4lf kg\n",value*0.4536);
	}
	return 0;
}