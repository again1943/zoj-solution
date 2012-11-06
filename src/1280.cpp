/*
 * =====================================================================================
 *
 *       Filename:  1280.cpp
 *
 *    Description:  solution to zoj 1280
 *
 *        Version:  1.0
 *        Created:  2007年10月21日 12时17分29秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

inline int cross_product( int x1, int y1, int x2, int y2)
{
	return 	x1*y2-x2*y1;
}

void intersect_point(int x1, int y1, int x2, int y2, int x3, 
			int y3, int x4, int y4,double* x,double* y)
{
	if( (x1 == x3&&y1==y3) || (x1 == x4 &&y1==y4))
	{
		*x = (double)x1;
		*y = (double)y1;
	}
	else if( (x2==x3&&y2==y3)||(x2==x4&&y2==y4))
	{
		*x = (double)x2;
		*y = (double)y2;
	}
	else
	{
		if( x1 == x2 )		
		{
			*x = (double)x1;
			*y = ((x1-x3)*(y4-y3)/(double)(x4-x3))+y3;
		}
		else if( y1 == y2 )
		{
			*x = ((y1-y3)*(x4-x3)/(double)(y4-y3))+x3;
			*y = (double)y1;
		}
		else if( x4 == x3 )
		{
			*x = (double)x3;	
			*y = (y2-y1)*(x3-x1)/(double)(x2-x1)+y1;
		}
		else if( y4 == y3 )
		{
			*y = (double)y3;
			*x = (y3-y1)*(x2-x1)/(double)(y2-y1)+x1;
		}
		else
		{
			int a1 = (y1*(x2-x1)-x1*(y2-y1))*(x4-x3);
			int a2 = (y3*(x4-x3)-x3*(y4-y3))*(x2-x1);
			int b1 = (y2-y1)*(x4-x3);
			int b2 = (y4-y3)*(x2-x1);
			int c = (x2-x1)*(x4-x3);
			*x = (a2-a1)/(double)(b1-b2);
			*y = ((*x)*b1+a1)/c;
		}
	}
}

int main()
{
	int n;	
	double x,y;
	int x1,y1,x2,y2,x3,y3,x4,y4;
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	for( int i = 0; i < n; i++ )
	{
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if( cross_product(x2-x1,y2-y1,x4-x3,y4-y3) == 0 )
		{
			if( cross_product(x3-x2,y3-y2,x4-x1,y4-y1) != 0 ||
				cross_product(x3-x1,y3-y1,x4-x2,y4-y2) != 0 )
				printf("NONE\n");
			else
				printf("LINE\n");
		}
		else
		{
			intersect_point(x1,y1,x2,y2,x3,y3,x4,y4,&x,&y);
			printf("POINT %0.2lf %0.2lf\n",x,y);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}


