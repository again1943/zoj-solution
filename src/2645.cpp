#include<cstdio>
using namespace std;
#define IP_LEN 20


unsigned long ip_long( char* ip )
{
	int pos = 0;
	unsigned long part;
	unsigned long ret_ip = 0;		
	for( int i = 1; i <= 4; i++ )
	{
		part = 0;
		while( ip[pos] != '.' && ip[pos] != '\0' )	
			part = part*10+ip[pos++]-'0';
		ret_ip |= (part << (4-i)*8);
		pos++;
	}
	return ret_ip;
}

char* ip_string( unsigned long ip )
{
	int pos = 0;
	unsigned long left = 24;
	unsigned long result;
	unsigned long mask = 0xff000000;
	static char ip_str[IP_LEN];
	for( int i = 0; i < 4; i++ )
	{
		result = (ip&mask) >> left;	
		if( result/100 != 0 )
		{
			ip_str[pos++] = result/100+'0';
			result %= 100;
			ip_str[pos++] = result/10+'0';
			result %= 10;
		}
		else if( result/10 != 0 )
		{
			ip_str[pos++] = result/10+'0';
			result %= 10;
		}
		ip_str[pos++] = result+'0';
		ip_str[pos++] = '.';
		mask >>= 8;
		left -= 8;
	}
	ip_str[pos-1] = '\0';
	return ip_str;
}
unsigned long diff_bit( unsigned long x,unsigned long y)
{
	int t = 0;	
	while( x != y )
	{
		x >>= 1;	
		y >>= 1;
		t++;
	}
	return t;
}

int main()
{
	int n;	
	unsigned long mk;
	unsigned long ip;
	unsigned long mask;
	char ip_str[IP_LEN];
	while(scanf("%d",&n) != -1)
	{
		scanf("%s",ip_str);
		ip = ip_long(ip_str);
		mask = 0xffffffff;
		if( n > 1 )
		{
			scanf("%s",ip_str);
			mk = diff_bit(ip,ip_long(ip_str));
			if( mk == 32 )
				mask = 0;
			else
				mask = (mask >> mk) << mk;
			ip &= mask;
			for( int i = 2; i < n ;i++ )
			{
				scanf("%s",ip_str);
				mk = diff_bit(ip,ip_long(ip_str));
				if( mk == 32 )
					mask = 0;
				else
					mask = (mask >> mk) << mk;
				ip &= mask;
			}
		}
		printf("%s\n",ip_string(ip));
		printf("%s\n",ip_string(mask));
	}
	return 0;
}



