#include<cstdio>
using namespace std;

int main()
{
	bool flag;
	int H,U,D,F,day;
	double percentage,u,total;
	while( scanf("%d%d%d%d",&H,&U,&D,&F) && H != 0 )
	{
		flag = false;
		u = U;
		percentage = u*F/100;
		for( day = 1,total = 0;; day += 1 ) 
		{
			if( total + u > H )
			{
				flag = true;
				break;
			}
			total += u-D;
			if( total < 0 )
				break;
			u -= percentage;
			if( u < 0 )
				u = 0;
		}
		printf("%s on day %d\n",(flag?"success":"failure"),day);
	}
	return 0;
}
