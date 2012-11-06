#include<cstdio>

using namespace std;

int factorial[11];

bool check_yes( int n )
{
	int i = 10;	
	while( i >= 0 )
	{
		while( n < factorial[i] )	
			i--;
		if( n == factorial[i] )
			return true;
		else
			n -= factorial[i--];

	}
	return false;
}
int main()
{
	int n;
	
	factorial[0] = factorial[1] = 1;
	for( int i = 2; i < 11; i++ )
		factorial[i] = factorial[i-1]*i;
	scanf("%d",&n);
	while( n >= 0 )
	{
		if( n == 0 )
			printf("NO\n");
		else
			printf("%s\n",(check_yes(n) == true ? "YES":"NO"));
		scanf("%d",&n);
	}

	return 0;
}
