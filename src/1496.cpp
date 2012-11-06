#include<cstdio>
#include<utility>
#include<cstdlib>
#include<algorithm>
#include<numeric>
using namespace std;
#define PI 3.14159
int f[3];
int r[9];
double diameter,target;

#define eps 1e-10
inline double myabs( double t )
{
	if( t > eps )
		return t;
	else if( t < -eps )
		return -t;
	else
		return 0;
}
double do_work( int* f,int* r,double diameter,double target,pair<int,int>& ret )
{
	int i,j;
	double value;
	double min_v = 10000000;
	for( i = 0; i < 3; i++ )
	for( j = 0; j < 9; j++ )
	{
		value = myabs(((double)f[i]/r[j])*diameter*PI-target);
		if( min_v > value )
		{
			ret.first = f[i];
			ret.second = r[j];
			min_v = value;
		}
	}
	return ((double)ret.first/ret.second)*diameter*PI;
}
int main()
{
	int n,i,j;
	double result;
	pair<int,int> ret;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		if( i != 0 )
			printf("\n");
		for( j = 0; j < 3; j++ )	
			scanf("%d",&f[j]);
		for( j = 0; j < 9; j++ )
			scanf("%d",&r[j]);
		scanf("%lf%lf",&diameter,&target);
		result = do_work(f,r,diameter,target,ret);
		printf("A gear selection of %d/%d produces a gear size of %0.3lf.\n",
			ret.first,ret.second,result);
	}
	return 0;
}
