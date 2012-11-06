#include<cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_LINE 100004
char source[MAX_LINE];
char result[MAX_LINE];

int action(char* source, char* result, int start, int end)
{
	char c;
	int n = 0;
	bool forward = true;
	while( (c = getchar()) != '#' )
	{
		if( c == 'G' && start <= end )
		{
			if( forward == true )
				result[n++] = source[start++];
			else
				result[n++] = source[end--];
		}
		else if( c == 'R' )
			forward = (forward == true?false:true);
		else
			continue;
	}
	source[n] = 0;
	return n;
}
int main()
{
	int t,n,i,k,start,end,len;
	scanf("%d",&t);
	for( k = 0; k < t; k++)
	{
		if( k != 0 )
			printf("\n");
		scanf("%d",&n);
		gets(source);
		gets(source);
		end = strlen(source);
		for(i = 1; i < n; i++)
		{
			gets(source+end);
			end = (int)strlen(source);
		}
		start = 0;
		len = action(source,result,start,end-1);
		//printf("%s\n",result);
		for( i  = 1; i <= len; i++ )
		{
			printf("%c",result[i-1]);
			if( i % 80 == 0)
				printf("\n");
		}
		if( i%80 != 0 )
			printf("\n");
	}
	return 0;
}