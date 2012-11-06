#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

template<typename T>
struct point_t
{
	T x,y;
};

struct desc_t
{
	int n1;
	int n2;
	int idx1[5];
	int pp1[5];
	int idx2[5];
	int pp2[5];
};
desc_t desc[16] = 
{
	{3,3,{0,1,2},{0,0,0},{2,3,0},{0,0,0}},
	{3,3,{0,1,3},{0,0,0},{1,2,3},{0,0,0}},

	{3,5,{1,1,0},{0,1,1},{1,2,3,0,0},{1,0,0,0,1}},
	{3,5,{1,2,2},{1,0,1},{1,2,3,0,1},{1,1,0,0,0}},
	{3,5,{2,3,3},{1,0,1},{2,3,0,1,2},{1,1,0,0,0}},
	{3,5,{3,0,0},{1,1,0},{3,0,1,2,3},{1,1,0,0,0}},
	{4,4,{0,1,2,2},{1,0,0,1},{0,2,3,0},{1,1,0,0}},
	{4,4,{3,1,1,0},{1,1,0,0},{3,1,2,3},{1,1,0,0}},

	{3,4,{0,1,1},{0,0,1},{0,1,2,3},{0,1,0,0}},
	{3,4,{0,2,3},{0,1,0},{0,2,2,1},{0,1,0,0}},
	{3,4,{0,0,3},{0,1,0},{3,2,1,0},{0,0,0,1}},
	{3,4,{3,2,1},{0,0,1},{3,0,1,1},{0,0,0,1}},
	{3,4,{2,3,3},{0,0,1},{2,1,0,3},{0,0,0,1}},
	{3,4,{2,1,0},{0,0,1},{2,3,0,0},{0,0,0,1}},
	{3,4,{1,2,2},{0,0,1},{1,0,3,2},{0,0,0,1}},
	{3,4,{1,0,3},{0,0,1},{1,2,3,3},{0,0,0,1}},
};
typedef point_t<int> pointi;
typedef point_t<double> pointd;
pointi poly[4];
pointd midp[4];
pointd polyd[4];

double inline area3( pointd& a, pointd& b, pointd& c )
{
	return fabs(a.x*b.y+a.y*c.x+b.x*c.y-
		c.x*b.y-a.y*b.x-c.y*a.x)/2.0;
}
double inline area4(pointd& a, pointd& b, pointd& c, pointd& d )
{
	return area3(a,b,c)+area3(c,d,a);
}
double inline area5(pointd& a, pointd& b, pointd& c, pointd& d , pointd& e )
{
	return area4(a,b,c,d)+area3(d,e,a);
}
void calc( pointd* polyd, pointd* midp, int idx, double& s, double& t )
{
	pointd* m[2];	
	m[0] = polyd;
	m[1] = midp;
	desc_t d = desc[idx];
	if( d.n1 == 3 )
		s = area3(m[d.pp1[0]][d.idx1[0]],
			m[d.pp1[1]][d.idx1[1]],
			m[d.pp1[2]][d.idx1[2]]);
	else if( d.n1 == 4 )
		s = area4(m[d.pp1[0]][d.idx1[0]],
			m[d.pp1[1]][d.idx1[1]],
			m[d.pp1[2]][d.idx1[2]],
			m[d.pp1[3]][d.idx1[3]]);
	else
		s = area5(m[d.pp1[0]][d.idx1[0]],
			m[d.pp1[1]][d.idx1[1]],
			m[d.pp1[2]][d.idx1[2]],
			m[d.pp1[3]][d.idx1[3]],
			m[d.pp1[4]][d.idx1[4]]);
	if( d.n2 == 3 )
		t = area3(m[d.pp2[0]][d.idx2[0]],
			m[d.pp2[1]][d.idx2[1]],
			m[d.pp2[2]][d.idx2[2]]);
	else if( d.n2 == 4 )
		t = area4(m[d.pp2[0]][d.idx2[0]],
			m[d.pp2[1]][d.idx2[1]],
			m[d.pp2[2]][d.idx2[2]],
			m[d.pp2[3]][d.idx2[3]]);
	else
		t = area5(m[d.pp2[0]][d.idx2[0]],
			m[d.pp2[1]][d.idx2[1]],
			m[d.pp2[2]][d.idx2[2]],
			m[d.pp2[3]][d.idx2[3]],
			m[d.pp2[4]][d.idx2[4]]);
}
void detail( pointd* polyd,  pointd* midp,double& a, double& b )
{
	int i;
	double s,t,v;
	double abv = 12345678.00;
	for( i = 0; i < 16; i++ )
	{
		calc(polyd, midp,i,s,t);
		if( (v = fabs(s-t)) < abv )
		{
			a = s;
			b = t;
			abv =v;
		}
	}
	if( a > b )
		swap(a,b);
}
int main()
{
	int i;
	int t = 0;
	double a,b;
	while( scanf("%d%d%d%d%d%d%d%d",&poly[0].x,&poly[0].y,
		&poly[1].x,&poly[1].y,&poly[2].x,&poly[2].y,
		&poly[3].x,&poly[3].y) && (poly[0].x != 0 || 
		poly[0].y != 0 || poly[1].x != 0 || poly[1].y != 0 ||
		poly[2].x != 0 || poly[2].y != 0 || poly[3].x != 0 ||
		poly[3].y != 0 ))
	{
		for( i = 0; i < 4; i++ )
		{
			polyd[i].x = poly[i].x;
			polyd[i].y = poly[i].y;
		}
		midp[0].x = (poly[0].x+poly[1].x)/2.0;
		midp[0].y = (poly[0].y+poly[1].y)/2.0;
		midp[1].x = (poly[1].x+poly[2].x)/2.0;
		midp[1].y = (poly[1].y+poly[2].y)/2.0;
		midp[2].x = (poly[2].x+poly[3].x)/2.0;
		midp[2].y = (poly[2].y+poly[3].y)/2.0;
		midp[3].x = (poly[3].x+poly[0].x)/2.0;
		midp[3].y = (poly[3].y+poly[0].y)/2.0;
		detail(polyd, midp,a,b);
		printf("Cake %d: %0.3lf %0.3lf\n",++t,a,b);
	}
	return 0;
}
