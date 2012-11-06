#include<cstdio>
using namespace std;

char number[] = "9`12345678";
char charact[] = " VXSWDFGUHJKNBIO EARYCQZT ";

char get_code( char c )
{
	if( c == ' ' || c == '\n' )
		return c;
	if( c >= '0' && c <= '9' )
		return number[c-'0'];
	if( c >= 'A' && c <= 'Z' )
		return charact[c-'A'];
	switch( c )
	{
		case '-':
			return '0';
		case '=':
			return '-';
		case '[':
			return 'P';
		case ']':
			return '[';
		case '\\':
			return ']';
		case ';':
			return 'L';
		case '\'':
			return ';';
		case ',':
			return 'M';
		case '.':
			return ',';
		case '/':
			return '.';
		default:
			return 0;
	}
}

int main()
{
	int c;
	while( (c=getchar()) != -1 )
		putchar(get_code(c));
	return 0;
}
