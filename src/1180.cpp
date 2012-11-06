#include<cstdio>
#define MAX 1000001
int main()
{
	bool field[MAX];
	int index;
	int a,b,c,d,e,f;
	for( a = 0; a < 10; a++ )
	for( b = 0; b < 10; b++ )
	for( c = 0; c < 10; c++ )
	for( d = 0; d < 10; d++ )
	for( e = 0; e < 10; e++ )
	for( f = 0; f < 10; f++ )
	{
		index = 100001*a + 10001*b + 1001*c + 101*d + 11*e + 2*f;
		index  = (index >= MAX)?0:index;
		field[index] = true;
	}
	for( int i = 1; i < MAX; i++ )
		if( field[i] == false )
			printf("%d\n",i);
	return 0;
}
