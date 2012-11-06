#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct tuple
{
	int a,b;
	tuple(int x=0, int y=0):a(x),b(y){}
	bool operator==(const tuple& tup)
	{
		return (a == tup.a && b == tup.b);
	}
	bool operator<(const tuple& tup)
	{
		if( a != tup.a )
			return a < tup.a;
		return b < tup.b;
	}
};

struct sort_policy
{
	bool operator()(const tuple& a, const tuple& b)
	{
		if( a.a != b.a )
			return a.a > b.a;
		return a.b > b.b;
	}
};
double doit(int A, int B, int C, int D, double p)
{
	tuple tup;
	double ret = 0;
	double eps = 1e-4;
	map<tuple,double,sort_policy>X,Y,*x,*y;
	map<tuple,double,sort_policy>::iterator iter,it;
	x = &X;
	y = &Y;
	x->insert(make_pair(tuple(A,B),1.0));
	while( x->empty() != true )
	{
		for( iter = x->begin(); iter != x->end(); ++iter )
		{
			if( iter->first.a-C >= 0 && iter->second > eps )
			{
				tup = tuple(iter->first.a-C,iter->first.b+C);//item.second*p);
				if( (it = y->find(tup)) != y->end() )
					it->second += iter->second*p;
				else
					y->insert(make_pair(tup,iter->second*p));
			}
			if( iter->first.b-D >= 0 && iter->second > eps )
			{
				tup = tuple(iter->first.a+D,iter->first.b-D);//item.p*(1-p));
				if( (it = y->find(tup)) != y->end() )
					it->second += iter->second*(1-p);
				else
					y->insert(make_pair(tup,iter->second*(1-p)));
			}
			if( iter->first.b - D < 0 )
				ret += iter->second*(1-p);
		}
		swap(x,y);
		y->clear();
	}
	return ret;
}
int main()
{
	int A,B,C,D,T,i;
	double p;
	scanf("%d",&T);
	for( i = 0; i < T; i++ )
	{
		scanf("%d%d%d%d%lf",&A,&B,&C,&D,&p);
		printf("%0.2lf\n",doit(A,B,C,D,p));
	}
	return 0;
}