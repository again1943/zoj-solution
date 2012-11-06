#include <cstdio>
#include <cstring>
#define MAX_LINE 240

char source[MAX_LINE];
char target[MAX_LINE];
char special[] = " !$%()*";
char replace[][6] = {"%20","%21","%24","%25","%28","%29","%2a"};
int idx( char c)
{
	for( int i = 0; special[i] != 0; i++ )
		if( c == special[i])
			return i;
	return -1;
}
int main()
{
	int i,n,d;
	while(gets(source) && strcmp(source,"#") != 0)
	{
		for( i = n = 0; source[i] != 0; i++ )
		{
			if( (d = idx(source[i])) < 0 )
				target[n++] = source[i];
			else
			{
				target[n] = replace[d][0];
				target[n+1] = replace[d][1];
				target[n+2] = replace[d][2];
				n += 3;
			}
		}
		target[n] = 0;
		printf("%s\n",target);
	}
	return 0;
}