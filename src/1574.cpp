#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define TRIPLE_LEN 100000

struct triple_t
{
	int x,y,z;
}triple[TRIPLE_LEN];

int gcd( int x, int y)
{
	int tmp;
	int max_ = max(x,y);
	int min_ = min(x,y);
	if( min_ == 0 )
		return max_;
	else
	{
		while( max_%min_ != 0 )
		{
			tmp = min_;
			min_ = max_%min_;
			max_ = tmp;
		}
		return min_;
	}
}

void pre_do()
{
	int i,j,n,u,v,x,y,t;
	for( i = 3,n = 0;  n < TRIPLE_LEN; i++ ) 
	{
		if( i % 2 == 1 )	
		{
			for( j = (int)sqrt((double)i); j >= 1; j-- )		
			{
				if( i%j == 0 )
				{
					u = (j+i/j)/2;
					v = u-j;
					if( (u-v) % 2 != 0 && gcd(u,v) == 1 &&
						(y = 2*u*v)>i && gcd(y,i) == 1 )
					{
						triple[n].x = i;	
						triple[n].y = y;
						triple[n++].z = u*u+v*v;
					}
				}
			}
		}
		else
		{
			if( (t = i/2)%2 != 0 )
				continue;
			for( j = (int)sqrt((double)t); j >= 1; j-- )		
			{
				if( t%j == 0 )
				{
					u = t/j;
					v = j;
					if( (u-v) % 2 != 0 && gcd(u,v) == 1 &&
						(y = u*u-v*v)>( x = 2*u*v ) && gcd(y,x) == 1 )
					{
						triple[n].x = x;
						triple[n].y = y;
						triple[n++].z = u*u+v*v;
					}
				}
			}
		}
	}
}
int main()
{
	int n;			
	pre_do();
	while( scanf("%d",&n) != -1 )
		printf("%d %d %d\n",triple[n-1].x,
			triple[n-1].y,triple[n-1].z);
	return 0;
}
