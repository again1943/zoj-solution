#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MAX_LINE 256
#define IMPOSSIBLE -1
#define IDENTITY -2

char line[MAX_LINE];

int eat(char* line ,int& start )
{
	int base = 0;
	while( line[start] >= '0' && line[start] <= '9' )	
		base = base*10+line[start++]-'0';
	return base;
}

void parse( char* line ,int start, int end, int& x, int& c )
{
	int i = start;
	int base = 1;
	int flag = 1;
	x = c = 0;
	while( i < end )
	{
		if( line[i] >= '0' && line[i] <= '9' )
		{
			base = eat(line,i);
			if( line[i] == 'x' )
			{
				i += 1;
				x += flag*base;
			}
			else
				c += flag*base;	
			base = flag = 1;
		}
		else if( line[i] == '+' )
		{
			flag = 1;
			i += 1;
		}
		else if( line[i] == '-' )
		{
			flag = -1;
			i += 1;
		}
		else//only x
		{
			i += 1;
			x += flag;	
			flag = 1;
		}
	}
}
int solve( char* line )
{
	double retval;
	int i,base;
	int leftx,leftc;
	int rightx,rightc;
	int len = strlen(line);
	int equ = find(line,line+len,'=')-line;
	parse(line,0,equ,leftx,leftc);
	parse(line,equ+1,len,rightx,rightc);
	leftx -= rightx;
	leftc -= rightc;
	if( leftx == 0 && leftc == 0 )
		printf("IDENTITY\n");
	else if( leftx == 0 && leftc != 0 )
		printf("IMPOSSIBLE\n");
	else
	{
		retval = -leftc*1.0/leftx;
		printf("%d\n",(retval>=0)?(int)retval:((int)retval)-1);
	}
}
int main()
{
	int n,i,retval;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%s",line);	
		solve(line);
	}
	return 0;
}
