/*
 * =====================================================================================
 *
 *       Filename:  1152.cpp
 *
 *    Description:  solution to zoj 1152
 *
 *        Version:  1.0
 *        Created:  2007年05月04日 10时14分26秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cstdio>
using namespace std;

int main()
{
	int c,s,u;
	int t = 0;
	int n,m;
	scanf("%d",&c);
	while( c-- )
	{
		if( t++ )
			printf("\n");
		scanf("%d%d",&n,&m);
		s = 0;
		while( m != 0 || n != 0 )
		{
			s++;
			u = 0;
			for( int a = 1; a < n; a++ )
			for( int b = a+1; b < n; b++ )
				if( (a*a+b*b+m)%(a*b) == 0 )
				{
#ifdef DEBUG
			printf("a = %d b = %d m = %d\n",a,b,m);
			printf("a*a+b*b+m = %d a*b = %d\n",a*a+b*b+m,a*b);
#endif
					u++;
				}
			printf("Case %d: %d\n",s,u);
			scanf("%d%d",&n,&m);
		}
	}
	return 0;
}

