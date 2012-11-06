#include<cstdio>
using namespace std;

#define SIZE 100

char result[SIZE];

int dfs( int start, int n,int top )
{
	int temp;
	if( top >= SIZE )	
		return -1;
	else if( start%n == 0 )
		return top;
	else
	{
		start %= n;
		result[top++] = '0';	
		if( (temp = dfs(start*10,n,top)) > 0 )
			return temp;
		top--;
		result[top++] = '1';
		return dfs(start*10+1,n,top);
	}
}

int main()
{
	int n;
	int top;
	while( scanf("%d",&n) && n != 0 )
	{
		result[0] = '1';
		top = 1;
		top = dfs(1,n,top);
		if( top > 0 )
		{
			result[top] = '\0';
			printf("%s\n",result);
		/*
			for( int i = 0; i < top; i++ )
				printf("%d",result[i]);
			printf("\n");	
			*/
		}
		else
			printf("failed\n");
	}
	return 0;
}
