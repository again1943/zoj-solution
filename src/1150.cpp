#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define VAR_CNT 8
#define STR_LEN 256
char value[STR_LEN];
char result[STR_LEN];
int varible[VAR_CNT];

int shuff( char* source, int* varible, int n )
{
	int i;
	int ret = 0;
	char temp[24];
	strcpy(temp,source);
	for( i = 0; i < n; i++ )
	{
		source[i] = temp[varible[i]];	
		ret += ((source[i]-'0') << (n-1-i));
	}
	return ret;
}
int main()
{
	int n,m,code,i;
	char temp[24];
	int t = 0;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )	
		{
			scanf("%s",temp);
			varible[i] = atoi(temp+1)-1;
		}
		scanf("%s",value);
		scanf("%d",&m);
		for( i = 0; i < m; i++ )
		{
			scanf("%s",temp);	
			code = shuff(temp,varible,n);
			result[i] = value[code];	
		}
		result[m] = 0;
		printf("S-Tree #%d:\n%s\n\n",++t,result);
	}
	return 0;
}
