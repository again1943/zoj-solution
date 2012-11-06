#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_LINE 512
char line[MAX_LINE];
char code[MAX_LINE];
char* letter = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int step[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int turn[4][3] = {{1,0,1},{0,-1,2},{-1,0,3},{0,1,0}};

inline bool inside( int x, int y, int n, int m ) 
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}
inline int next( int& x, int& y, int& d, int n, int m )
{
	int a,b,c;
	c = line[x*m+y]-'0';
	line[x*m+y] = 0;
	a = x+step[d][0];
	b = y+step[d][1];
	if( !inside(a,b,n,m) || line[a*m+b] == 0 )
	{
		a = x+turn[d][0];
		b = y+turn[d][1];
		d = turn[d][2];
	}
	x = a;
	y = b;

	return c;
}
inline char extract( int& x, int& y, int& d, int n, int m )
{
	int i,c;		
	for( i = c = 0; i < 5; i++ )
		c = (c<<1)+next(x,y,d,n,m);
	return letter[c];	
}
void decode(char* line, char* code, int n, int m)
{
	int x,y,d,s,i;
	s = (n*m)/5;
	x = y = d = 0;	
	for( i = 0; i < s; i++ )
		code[i] = extract(x,y,d,n,m);	
	while( i >= 0 )
	{
		if( code[i-1] != ' ' )
			break;
		i -= 1;
	}
	code[i] = 0;
}
int main()
{
	int t,k,n,m;
	scanf("%d",&t);
	for(k = 1; k <= t; k++ )
	{
		scanf("%d%d%s",&n,&m,line);
		decode(line,code,n,m);
		printf("%d %s\n",k,code);
	}
	return 0;
}
