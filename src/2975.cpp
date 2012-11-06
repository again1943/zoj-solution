#include <cstdio>
#include <cstring>

#define MAX_LINE 256
char table[MAX_LINE][MAX_LINE];
//char output[8192];

char* word = "BJHYN";
int dp(int m, int n)
{
	int i,j,k,x,c;
	int ret = 0;
	for( i = 0; i < m; i++ )
	for( j = i+1; j < m; j++)
	for( k = 0; k < 5; k++ )
	{
		c = 0;
		for( x = 0; x < n; x++ )
			if( table[i][x] == word[k] && table[j][x] == word[k] )
				c += 1;
		if( c > 0 )
			ret += c*(c-1)/2;
	}
	return ret;

}
int main()
{
	int n,m,t,k,i;
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d%d",&m,&n);
		for( i = 0; i < m; i++ )
			scanf("%s",table[i]);
		printf("%d\n",dp(m,n));
	}
	return 0;
}