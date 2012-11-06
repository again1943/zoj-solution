#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 1000004
char text[MAXN];
int  period[MAXN];

int main()
{
	int n,i,k;
	int c = 0;
	while( scanf("%d",&n) && n != 0 )
	{
		scanf("%s",text);	
		printf("Test case #%d\n",++c);
		period[0] = -1;
		for( i = 1; i < n; i++ )
		{
			k = period[i-1];
			while( text[k+1] != text[i] && k >= 0 )
				k = period[k];
			if( text[k+1] == text[i] )
				k += 1;
			period[i] = k;	
			if( period[i]+1 >= (i+1)/2 && (i+1)%(i-period[i]) == 0 )
				printf("%d %d\n",i+1,(i+1)/(i-period[i]));
		}
		printf("\n");
	}
	return 0;
}
