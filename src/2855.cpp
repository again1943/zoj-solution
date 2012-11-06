#include<cstdio>
#include<cmath>
using namespace std;
#define MAX_TAG 64
char tag[MAX_TAG];

const double pi = acos(-1.0);
inline double longitude( double x )
{
	return x*pi/180;	
}
inline double latitude( double x )
{
	return log(tan(pi/4+(x*pi/360)));
}

const double left = longitude(-180);
const double right = longitude(180);
const double up = latitude(85);
const double down = latitude(-85);

void map(double x,double y,int level,double left,
		double right,double up,double down)
{
	int tag_idx = 1;
	tag[0] = 't';
	double midx,midy;
	x = longitude(x);
	y = latitude(y);
	while( level != 0 )		
	{
		midx = (left+right)/2;
		midy = (up+down)/2;
		if( x > midx && y > midy )
		{
			left = midx;		
			down = midy;
			tag[tag_idx++] = 'r';
		}
		else if( x > midx && y < midy )
		{
			left = midx;	
			up = midy;
			tag[tag_idx++] = 's';
		}
		else if( x < midx && y > midy )
		{
			right = midx;	
			down = midy;
			tag[tag_idx++] = 'q';
		}
		else
		{
			right = midx;
			up = midy;	
			tag[tag_idx++] = 't';
		}
		level -= 1;
	}
	tag[tag_idx] = 0;
}
int main()
{
	int level;
	double x,y;	
	while( scanf("%lf%lf%d",&x,&y,&level) != -1 )
	{
		map(x,y,level,left,right,up,down);
		printf("%s\n",tag);
	}
	return 0;
}
