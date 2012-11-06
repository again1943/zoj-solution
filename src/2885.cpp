#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
#define MAX_LINE 16384
char line[MAX_LINE];

int order_height(char* line )
{
	int i;		
	int maxval;
	int value;
	for( i = value = maxval = 0; line[i] != 0; i++ )
	{
		if( line[i] == 'd' )	
		{
			value += 1;	
			maxval = max(maxval,value);
		}
		else
			value -= 1;
	}
	return maxval;
}

int binary_height( char* line, int& pos )
{
	int ret;
	int n = 0;
	int hbinary = 0;
	while( line[pos] != 0 )
	{
		if(line[pos] == 'u')			
		{
			pos += 1;
			return hbinary;
		}
		else
		{
			n += 1;
			pos += 1;
			if( (ret = binary_height(line,pos)+n) > hbinary )
				hbinary = ret;
		}
	}
	return hbinary;
}
int main()
{
	int t = 0;
	int horder,hbinary,pos;
	while( scanf("%s",&line) && strcmp(line,"#") != 0 )
	{
		horder = order_height(line);
		hbinary = binary_height(line,(pos = 0));
		printf("Tree %d: %d => %d\n",++t,horder,hbinary);
	}
	return 0;
}
