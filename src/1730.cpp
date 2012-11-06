#include<cstdio>
using namespace std;

int main()
{
	int n,c;
	scanf("%d",&n);
	for( int i = 0; i < n; i++ )
	{
		scanf("%d",&c);
		printf("%d\n",(c%2==0?c*(c-2):(c-1)*(c-1))/4);
	}
	return 0;
}
