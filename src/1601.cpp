/*
 * =====================================================================================
 *
 *       Filename:  1601.cpp
 *
 *    Description:  solution to zoj 1601
 *
 *        Version:  1.0
 *        Created:  2007年05月20日 13时44分08秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<queue>
#include<cstdio>
#include<cmath>

struct triple_t
{
	int x,y;
	double value;
};

void get_nearst(int i,double value, int bound,triple_t& triple)
{
	double tp;
	int temp = (int)(i*value)+1;	
	for( int j = 0; j < 3; j++,temp--)
	{
		tp = temp/(double)i;
#ifdef DEBUG
		printf("i  = %d,temp = %d\n",i,temp);
		printf("triple.value = %0.15lf\n",triple.value);
		printf("value = %0.15lf\n",tp);
#endif
	if( temp < bound &&
			std::fabs(triple.value-value) > std::fabs(tp - value ))
		{
			/*
#ifdef DEBUG
			printf("i  = %d,temp = %d\n",i,temp);
			printf("value = %0.15lf\n",(double)temp/i);
#endif
*/
			triple.x = i;
			triple.y = temp;
			triple.value = tp;
		}
	}
}
int main()
{
	double value;
	int n,bound;
	triple_t triple;

	while( std::scanf("%lf%d",&value,&n) != -1 )
	{
		bound = (int)(n/value)+1;
		bound = bound > n ? n:bound;
		triple.value = value+10;
		for( int i = 1; i <= bound; i++ )
			get_nearst(i,value,n+1,triple);
		std::printf("%d %d\n",triple.y,triple.x);
	}
	return 0;
}

