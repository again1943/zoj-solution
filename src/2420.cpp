#include<cstdio>
#include<cstring>
using namespace std;
const char* week[] = {"Sunday","Monday","Tuesday",
	"Wednesday","Thursday","Friday","Saturday"};
const int month[2][13] = 
{{0,31,28,31,30,31,30,31,31,30,31,30,31},{0,31,29,31,30,31,30,31,31,30,31,30,31}};

inline int leap_year( int year )
{
	if( (year%400 == 0)||(year%4==0)&&(year%100 != 0 ))			
		return 1;
	return 0;
}
inline int day_year( int year )
{
	return leap_year(year)?366:365;
}
int main()
{
	int duration,dayofyear,dayofmonth;
	int year,m,leap,weekly;
	while( scanf("%d",&duration) && duration >= 0 )
	{
		weekly = (duration+6)%7;
		year = 2000;
		dayofyear = day_year(year); 
		while( duration >=  dayofyear )
		{
			duration -= dayofyear;
			year += 1;	
			dayofyear = day_year(year);	
		}
		m = 1;
		leap = leap_year(year);
		dayofmonth = month[leap][m];		
		while( duration >= dayofmonth )
		{
			duration -= dayofmonth;	
			m += 1;
			dayofmonth = month[leap][m];
		}
		printf("%d-%s%d-%s%d %s\n",year,(m<10?"0":""),m,
			(duration+1<10?"0":""),duration+1,week[weekly]);
	}
	return 0;
}
