#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define LIMT 1e-10
int main()
{
	double root;
	int n,i,x,y,maxval,nr;
	while( scanf("%d",&n) && n != 0 )
  	{
    		maxval = -1;
    		for( i = 0;(x = (i*(i+1)*(i+2))/6) <= n; i++ )
    		{
			root = pow(n-x,1.0/3);
			if( abs((nr = nearbyint(root))-root) < LIMT )
				y = nr;
			else
      				y = (int)pow(n-x,1.0/3);
      			maxval = max(maxval,x+y*y*y);
    		}
    		printf("%d\n",maxval);
  	}
  	return 0;
}
