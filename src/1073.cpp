#include<cstdio>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define DIGIT_LEN 64
char line[DIGIT_LEN];
char plus[DIGIT_LEN];
bool used[DIGIT_LEN];
char cycle[DIGIT_LEN][DIGIT_LEN];

bool linear_find( char* line,int n )
{
	int i;
	for( i = 0; i < n; i++ )
	{
		if( used[i] == false && strcmp(line,cycle[i]) == 0 )
		{
			return used[i] = true;
		}
	}
	return false;
}

bool linear_add( char* plus,char* line )
{
	int carry = 0;
	int n = strlen(line);			
	for( int i = n-1; i >= 0; i-- )
	{
		carry += plus[i]-'0'+line[i]-'0';
		plus[i] = carry%10+'0';
		carry /= 10;
	}
	return carry == 0;
}
int main()
{
	int n,i;
	while( scanf("%s",line) != -1 )
	{
		n = strlen(line);
		memset(	used,0,sizeof(used));			
		copy(line,line+n+1,plus);
		copy(line,line+n+1,cycle[0]);
		for( i = 1; i < n; i++ )
		{
			copy(cycle[i-1]+1,cycle[i-1]+n,cycle[i]);
			cycle[i][n-1] = cycle[i-1][0];
			cycle[i][n] = '\0';
		}
		for( i = 1,used[0] = true; i < n; i++ )
		{
			if( linear_add(plus,line) == false ||
				linear_find(plus,n) == false )
			{
				printf("%s is not cyclic\n",line);
				break;	
			}
		}
		if( i == n )
			printf("%s is cyclic\n",line);
	}
	return 0;
}
