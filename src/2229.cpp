#include<cstdio>
#include<algorithm>
using namespace std;

#define INT_MAX___ 0x7fffffff
#define DOU_MAX__ 1e100
int main()
{
	int v,n,i,t,mstart;
	double marrvial;
	while( scanf("%d",&n) && n != 0 )
	{
		mstart = INT_MAX___;
		marrvial = DOU_MAX__;
		for( i = 0; i < n; i++ )	
		{
			scanf("%d%d",&v,&t);
			if( t >= 0 )
			{
				mstart = min(mstart,t);
				marrvial = min(marrvial,4500*3.6/v+t);
			}
		}
		if( (int)marrvial == marrvial )
			printf("%d\n",(int)marrvial);
		else
			printf("%d\n",(int)marrvial+1);
	}
	return 0;
}
