#include<cstdio>
#include<cstring>
using namespace std;

#define MAX_LINE 256
char line[MAX_LINE];

struct point_t
{
	int x,y;
};

void processed( const char* line )
{
	point_t last,current,temp;
	last.x = 300;
	last.y = 420;
	current.x = 310;
	current.y = 420;
	printf("300 420 moveto\n310 420 lineto\n");
	for( int i = 0; line[i] != 0; i++ )
	{
		temp =  current;
		if( line[i] == 'A' && current.x == last.x )
			current.x += (current.y>last.y?10:-10);
		else if( line[i] == 'V' && current.x == last.x )
			current.x += (current.y>last.y?-10:10);
		else if( line[i] == 'A' && current.y == last.y )
			current.y += (current.x>last.x?-10:10);
		else
			current.y += (current.x>last.x?10:-10);
		last = temp;
		printf("%d %d lineto\n",current.x,current.y);
	}
	printf("stroke\nshowpage\n");
}
int main()
{
	while( scanf("%s",line) != -1 )
		processed(line);
	return 0;
}