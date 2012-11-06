#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

struct circle_t
{
	double x;
	double y;
	double r;
};

int main()
{
	circle_t m,n;	
	const double pi = 3.14159265358979;
	double len,dplus,dminus,area;
	double cosa,sina,cosb,etha;
	while( scanf("%lf%lf%lf%lf%lf%lf",&m.x,&m.y,&m.r,&n.x,&n.y,&n.r) != -1)
	{
		if( m.r < n.r )
			swap(m,n);
		dplus = m.r+n.r;	
		dminus = m.r-n.r;
		len = sqrt((m.x-n.x)*(m.x-n.x)+(m.y-n.y)*(m.y-n.y));
		if( len  >= dplus )
			area = 0.000;
		else if( len <= dminus ) 
			area = pi*n.r*n.r;
		else
		{
			cosa = 0.5*(m.r*m.r+len*len-n.r*n.r)/(m.r*len);	
			cosb = 0.5*(n.r*n.r+len*len-m.r*m.r)/(n.r*len);	
			if( cosb < 0 )
				etha = pi-acos(-cosb);		
			else
				etha = acos(cosb);
			sina = sqrt(1-cosa*cosa);
			area = (m.r*m.r*acos(cosa)+n.r*n.r*etha)-sina*m.r*len;
		}
		printf("%0.3lf\n",area);
	}
	return 0;
}
