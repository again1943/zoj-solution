#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

char base[256];
char result[256];
char middle[256];
char letter[256];

inline bool within(int t, int a, int b)
{
	if( a % b != 0 )	
		return false;
	if( (a-b)*log10((double)t)+1 > 110)
		return false;
	return true;
}
void multi( char* a, char* b, char* c)
{
	int i,j,r,carry;
	memset(c,0,sizeof(char)*256);
	for( i = 0; a[i] != 0; i++ )
	{
		carry = 0;
		for( j = 0; b[j] != 0; j++ )
		{
			r = (b[j]-'0')*(a[i]-'0')+(c[i+j]?(c[i+j]-'0'):0)+carry;
			carry = r/10;
			r %= 10;
			c[i+j] = r+'0';
		}

		r = i+j;
		while( carry != 0 )
		{
			c[r++] = carry % 10 + '0';	
			carry /= 10;
		}
	}
	c[r] = 0;
}
void add(char* a, char* b)
{
	int i,carry,r;
	char* t;
	//memset(c,0,sizeof(char)*256);
	for( i = carry = 0; a[i] != 0 && b[i] != 0; i++ )
	{
		r = (a[i]-'0')+(b[i]-'0')+carry;
		a[i] = r%10+'0';
		carry = r/10;
	}
	t = (a[i]!=0)?a:b;
	while( t[i] != 0 )
	{
		r = t[i]-'0'+carry;	
		a[i++] = r%10+'0';
		carry = r/10;
	}
	if( carry != 0 )
		a[i++] = carry+'0';
	a[i] = 0;
}
void powb( char* result, int t,int b)
{
	if( b == 1 )											
	{
		int i = 0;					
		while( t != 0 )
		{
			result[i++] = t%10+'0';	
			t /= 10;
		}
		strcpy(base,result);
	}
	else if( b % 2 == 0 )
	{
		powb(result,t,b/2);

		multi(result,result,middle);
		strcpy(result,middle);
	}
	else
	{
		powb(result,t,b/2);	
		multi(result,result,middle);
		multi(middle,base,result);
	}
}

// a % b == 0, n = a/b
//result = t^(a-b)+t^(a-2*b)+....+t^b+1
bool action(int t, int a, int b, char* result)
{
	int i;
	memset(result,0,sizeof(result));				
	memset(middle,0,sizeof(middle));
	result[0] = '1';
	powb(letter,t,b);
	strcpy(middle,letter);
	for( i = b; i <= a-b; i += b )
	{
		add(result,middle);
		multi(middle,letter,base);
		memcpy(middle,base,sizeof(char)*256);
	}
	i = strlen(result);
	if( i >= 101 )
		return false;
	std::reverse(result,result+i);
	return true;

}
int main()
{
	int t,a,b;
	while(scanf("%d%d%d",&t,&a,&b) != -1)
	{
		memset(base,0,sizeof(base));
		memset(result,0,sizeof(result));
		memset(middle,0,sizeof(middle));
		memset(letter,0,sizeof(letter));
		if( t == 1 )
			printf("(%d^%d-1)/(%d^%d-1) is not an integer with less"
				" than 100 digits.\n",t,a,t,b);
		else if( a == b )
			printf("(%d^%d-1)/(%d^%d-1) 1\n",t,a,t,b);
		else if( !within(t,a,b) || action(t,a,b,result) == false )
			printf("(%d^%d-1)/(%d^%d-1) is not an integer with less"
			" than 100 digits.\n",t,a,t,b);
		else
			printf("(%d^%d-1)/(%d^%d-1) %s\n",t,a,t,b,result);
	}
	return 0;
}

