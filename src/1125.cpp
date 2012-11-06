#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define LINE_LEN 24
#define ZERO "0000000000000000"
#define ZERO_X "1000000000000000"
char line[LINE_LEN];
char buf[LINE_LEN];

double get_val( char* line )
{
	int i;
	int val = 0;
	int base = 2;
	double value = 1.0;
	if( strcmp(line,ZERO) == 0 || strcmp(line,ZERO_X ) == 0 )
		return 0.0;
	for( i = 8; i < 16; i++ )
	{
		if( line[i] != '0' )
			value += (line[i]-'0')*1.0/base;
		base *= 2;
	}
	for( i = 7,base = 1; i >= 1; i-- )
	{
		if( line[i] != '0' )
			val += base;
		base *= 2;
	}
	value *= pow(2.0,val-63);
	return (line[0] == '0')?value:-value;
}
int main()
{
	int len;
	printf("Program 6 by team X\n");
	while( scanf("%s",line) != -1 )
	{
		sprintf(buf,"%-6e",get_val(line));
		len = strlen(buf);
		buf[len+1] = 0;
		buf[len] = buf[len-1];
		buf[len-1] = buf[len-2];
		buf[len-2] = '0';
		if( buf[0] != '-' )
			printf(" ");
		printf("%s\n",buf);
	}
	printf("End of program 6 by team X\n");
	return 0;
}
