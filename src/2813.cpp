#include<cstdio>
#include<cstring>
using namespace std;
#define LINE_LEN 84
#define LEFT 0
#define RIGHT 1
char line[LINE_LEN];
int search( char* line,int i, int D,int n )
{
	int t;
	
	if( D == LEFT )
	{
		t = i-1;	
		while( t >= 0 )
		{
			if( line[t] == '.' )
				return 100;
			if( line[t] == '|' || line[t] == '\\' )
				return 0;	
			t--;
		}
		return 100;
	}
	else
	{
		t = i+1;	
		while( t < n )
		{
			if( line[t] == '.' )	
				return 100;
			if( line[t] == '|' || line[t] == '/' )
				return 0;
			t++;
		}
		return 100;
	}
}
int score( char* line, int i,int n)
{
	switch( line[i] )	
	{
		case '.':
			return 100;
		case '_':
			return 0;
		case '/':
			return search(line,i,LEFT,n);
		case '\\':
			return search(line,i,RIGHT,n);
		case '|':
			return search(line,i,LEFT,n)/2+
				search(line,i,RIGHT,n)/2;
		default:
			return 0;	
		
	}

}
int do_work( char* line )
{
	int i,n,p;
	n = strlen( line );
	for( i = p = 0; i < n; i++ )
		p += score(line,i,n);
	return p/n;
}
int main()
{
	while(scanf("%s",line) && strcmp(line,"#") != 0)
		printf("%d\n",do_work(line));
	return 0;
}
