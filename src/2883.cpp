#include<cstdio>
#include<functional>
#include<algorithm>
using namespace std;
#define GOODS_CNT 20002
int prices[GOODS_CNT];

int main()
{
	int test_case,i,k,n,total;
	scanf("%d",&test_case);
	for( k = 0; k < test_case; k++ )
	{
		scanf("%d",&n);
		for( i = 0; i < n; i++ )
			scanf("%d",&prices[i]);
		sort(prices,prices+n,greater<int>());
		for( i = total = 0; i+2 < n; i += 3 )
			total += prices[i+2];	
		printf("%d\n",total);
	}
	return 0;
}
