#include<cstdio>
using namespace std;

int main()
{
	int n;
	while( scanf("%d",&n) != -1 )
		printf("%d\n",(n*(9*n-7))/2+1);
	return 0;
}
