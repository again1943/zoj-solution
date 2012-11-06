#include <cstdio>
#include <cstring>
typedef unsigned int 	uint_t;
typedef unsigned short 	ushort_t;
typedef unsigned char	uchar_t;

#define MAXN 65536
void format_output(uint_t zeros, uint_t ones)
{
	int i;
	uint_t mask = 0x8000;
	for( i = 0; i < 16; i++ )	
	{
		if( (zeros&mask) != 0 )
			printf("0");
		else if( (ones&mask) != 0 )
			printf("1");
		else
			printf("?");
		zeros <<= 1;
		ones <<= 1;
	}
	printf("\n");
}

uchar_t touched[MAXN];

int main()
{
	uint_t	 x;
	uint_t a,b,c,s;
	uint_t zeros,ones;
	while( scanf("%d",&a) && a != 0 )
	{

		memset(touched,0,sizeof(touched));
		scanf("%d%d%d",&b,&c,&s);
		ones = s;
		zeros = ~s;
		touched[s] = 1;
		x = a*s+b;
		s = (uint_t)(x%c);

		while( touched[s] != 1 )
		{
			touched[s] = 1;	
			ones &= s;
			zeros &= ~s;
			x = a*s+b;
			s = (uint_t)(x%c);
		}
		format_output(zeros,ones);
	}
	return 0;
}

