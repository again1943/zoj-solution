#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int x;
	double esp = 1e-10;
	while( scanf("%d",&x ) != EOF )
	{
		int i = static_cast<int>(sqrt(8*static_cast<double>(x)+1)/2+0.500-esp );
		int y = x-(i*(i-1))/2;
		if( i%2 == 0 )
			printf("TERM %d IS %d/%d\n",x,y,i-y+1);
		else
			printf("TERM %d IS %d/%d\n",x,i-y+1,y);
	}
	return 0;
}
