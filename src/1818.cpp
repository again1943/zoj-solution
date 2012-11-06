#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int b,n,temp;
	scanf("%d%d",&b,&n);
	while( b != 0 )
	{
		temp = (int)(pow( b,static_cast<double>(1)/n));
		printf("%d\n",abs( pow((double)temp,n )-b ) < abs(pow((double)(temp+1),n)-b) ? temp:temp+1);	
		scanf("%d%d",&b,&n);
	}

	return 0;
}
