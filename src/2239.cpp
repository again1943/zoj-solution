/*
 * =====================================================================================
 *
 *       Filename:  acm2239.cpp
 *
 *    Description:  solution to zoj 2239
 *
 *        Version:  1.0
 *        Created:  2007年03月10日 19时22分45秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<cmath>
#include<cstdio>
using namespace std;

int main()
{
	int n,s,t;
	char x,y,c,z;

	scanf("%c%c%c%c",&x,&y,&c,&z);
	getchar();

	while( (x-'0') != 0 || (y-'0') != 0 )
	{
		t = z-'0';
		s = 1;
		n = ((x-'0')*10+(y-'0'));


		while( t-- )
			n *= 10; 

		t = n;
		while( t >>= 1 )
			s <<= 1;
		printf("%d\n",((n-s)<<1)+1);
		scanf("%c%c%c%c",&x,&y,&c,&z);
		getchar();
	}
	return 0;
}
