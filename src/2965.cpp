#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAXN 100

static int start[MAXN];

bool seven(int n)
{
	if( n % 7 == 0 )
		return true;
	while( n != 0 )
	{
		if( n % 10 == 7 )
			return true;
		n /= 10;
	}
	return false;
}
void calc()
{
	int i;
	int s,p,c;
	memset(start,-1,sizeof(start));

	start[1] = i = 7;
	s = 7;
	p = 1;
	c = 1;
	while( c < MAXN )
	{
		i += 1;
		if( seven(i) != true )
		{
			s = -1;
			p = 0;
		}
		else
		{
			if( s < 0 )
			{
				s = i;
				p = 1;
			}
			else
			{
				p += 1;
				if( start[p] < 0 )
				{
					start[p] = s;
					c = p;
				}
			}
		}
	}
}
int main()
{
	int p,n,i;
	calc();
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%d",&p);
		printf("%d\n",start[p]);
	}
	return 0;
}