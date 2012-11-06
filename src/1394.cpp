#include<cstdio>
#include<cstring>
using namespace std;

#define pi 3.14159

char start[20];

int main()
{
	double need;
	double x,y,z;	
	while( scanf("%s",start) && strcmp(start,"ENDOFINPUT") != 0 )
	{
		scanf("%lf%lf%lf",&x,&y,&z);
		scanf("%s",start);
		if( z > 180 )
			z = 360-z;

		need = (z*pi*x)/450;
		if( need <= y )
			printf("YES %d\n",(int)(y-need/5));
		else
			printf("NO %d\n",(int)(y*5));
	}
	return 0;
}
