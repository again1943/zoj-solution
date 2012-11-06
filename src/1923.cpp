#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAX_LINE 1024
char digit[MAX_LINE];
char factor[MAX_LINE];

bool testm( char* digit, int size, int n)
{
	int i,c;	
	for( c = 0, i = size-1; i >= 0; i-- )
		c = (c*10+digit[i]-'0')%n;
	return (c==0);
}

int divide(char* digit,int size, int n)
{
	int i,c;
	for( c = 0,i = size-1; i >= 0; i-- )		
	{
		c = c*10+digit[i]-'0';	
		digit[i] = c/n+'0';	
		c %= n;
	}
	i = size;
	while( digit[i-1] == '0' )
	{
		digit[i-1] = 0;
		i -= 1;
	}
	return i;
}
int decode( char* digit,char* factor)
{
	int i,n;
	int size = (int)strlen(digit);	
	std::reverse(digit,digit+size);
	for( i = 9,n = 0; i >= 2; i-- )
	{
		while( testm(digit,size,i) == true )		
		{
			factor[n++] = i+'0';
			size = divide(digit,size,i);	
		}
	}
	factor[n] = 0;
	if( digit[0] != '1' || digit[1] != 0 )
		return -1;
	std::sort(factor,factor+n);
	return 1;
}

int main()
{
	while( scanf("%s",&digit) && strcmp(digit,"-1") != 0 )
	{
		if( (digit[0] >= '0' || digit[0] <= '9')&&digit[1] == 0 )
			printf("1%c\n",digit[0]);
		else
		{
			if( decode(digit,factor) < 0 )	
				printf("There is no such number.\n");
			else
				printf("%s\n",factor);
		}
		memset(digit,0,sizeof(digit));
		memset(factor,0,sizeof(factor));
	}
	return 0;
}
