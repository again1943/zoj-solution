#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define LINE_LENGTH 32
char line[LINE_LENGTH];

int get_data( char* line, double& hours, int& speed )
{
	hours = ((line[0]-'0')*10+(line[1]-'0'))
		+((line[3]-'0')*10+(line[4]-'0'))/(double)60
		+((line[6]-'0')*10+(line[7]-'0'))/(double)3600;
	if( line[8] == ' ' )
		speed = atoi(line+9);
	else
		speed = -1;
	return speed;
}
int main()
{
	int speed;
	double hours;
	int lastspeed = 0;
	double lasthours = 0;
	double lastmile = 0;	
	while( gets(line) != 0 )
	{
		if( get_data(line,hours,speed) < 0 )	
		{
			lastmile += lastspeed*(hours-lasthours);
			lasthours = hours;
			for( int i = 0; i < 8; i++ )
				printf("%c",line[i]);
			printf(" %0.2lf km\n",lastmile);
		}
		else
		{
			lastmile += lastspeed*(hours-lasthours);	
			lastspeed = speed;
			lasthours = hours;
		}
	}
	return 0;
}
