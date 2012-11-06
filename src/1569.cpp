#include<cstdio>
#include<algorithm>
using namespace std;

#define SIZE 5000

int mod[SIZE];

int main()
{
	int n,m,x,sum;	
	while( scanf("%d%d",&n,&m) != -1 )
	{
		fill(mod,mod+m,0);
		sum = 0;		
		mod[0] = 1;
		for( int i = 0; i < n; i++)
		{
			scanf("%d",&x);
			sum += x;
			mod[(sum = sum%m)]++;	
		}
		sum = 0;
		for( int i = 0; i < m; i++) 
			sum += ((mod[i]-1)*mod[i])/2;	
		printf("%d\n",sum);
	}
	return 0;
}
