#include<cstdio>
#include<cstdlib>
using namespace std;

double rate[6][6];
int order[50];

int main()
{
	int test_case;
	int n;
	int money_int;
	double money_dou;
	scanf("%d",&test_case);
	for( int t = 0; t < test_case; t++ )
	{
		if( t != 0 )
			printf("\n");
		for( int i = 1; i <= 5; i++ )
		for( int j = 1; j <= 5; j++ )
			scanf("%lf",&rate[i][j]);
		while( scanf("%d",&n) && n != 0 )
		{
			order[0] = 1;
			for( int i = 1; i <= n; i++ )
				scanf("%d",&order[i]);
			order[n+1] = 1;
			n += 2;

			scanf("%lf",&money_dou);
			for( int i = 1; i < n; i++ )
			{
				money_dou = money_dou*rate[order[i-1]][order[i]];
				money_int = (int)(money_dou*100+0.5);
				money_dou = money_int/100.00;
			}
			printf("%0.2lf\n",money_dou);
		}
	}
	return 0;
}
