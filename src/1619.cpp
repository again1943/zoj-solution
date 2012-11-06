#include<cstdio>
using namespace std;
#define PEOPLE_CNT 101 

double cnt[PEOPLE_CNT];
void pre_do()
{
	int i;
	cnt[0] = 1;
	cnt[1] = 0;
	cnt[2] = 1;
	for( i = 3; i < PEOPLE_CNT; i++ )
		cnt[i] = (i-1)*(cnt[i-1]+cnt[i-2]);
}
double present(int n,int m )
{
	int i;
	double ret = cnt[n-m];
	for( i = n-m; i >= 2; i-- )
		ret /= i;
	for( i = m; i >= 2; i-- )
		ret /= i;
	return ret;
}
int main()
{
	int m,n;
	pre_do();
	while(scanf("%d%d",&n,&m) != -1)
		printf("%0.8lf\n",present(n,m));
	return 0;
}
