#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAXSTR 1024
#define MAXBASE 24
char w[MAXSTR];
char m[MAXBASE];

int mod( int base, char* w, char* m )
{
	int i,j;
	int mb,wb;	
	for( i = mb = 0; m[i] != 0; i++ )
		mb  = mb*base+(m[i]-'0');
	for( i = wb = 0; w[i] != 0; i++ )
	{
		wb = wb*base+(w[i]-'0');	
		wb %= mb;
	}
	return wb;
}

void format( int num, int base )
{
	int idx = 0;
	char str[MAXBASE];
	if( num == 0 )
	{
		str[idx++] = '0';
		str[idx] = 0;
	}
	else
	{
		while( num != 0 )	
		{
			str[idx++] = num%base+'0';
			num /= base;
		}
		str[idx] = 0;
		std::reverse(str,str+idx);
	}
	printf("%s\n",str);
}

int main()
{
	int base;
	while( scanf("%d",&base) && base != 0 )
	{
		scanf("%s%s",w,m);
		format(mod(base,w,m),base);
	}
	return 0;
}
