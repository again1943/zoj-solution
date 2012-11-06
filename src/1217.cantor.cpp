#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

#define MAX_ELEMS 362880

struct node_t
{
	int			parent;
	bool		taken;
	char		letter;
}nodes[MAX_ELEMS];


int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

char direction[] =  {'d','u','r','l'};

int base10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int factor[] = {1,1,2,6,24,120,720,5040,40320,362880};

inline int extract(int v, int p)
{
	return ((v/base10[p])*base10[p])%base10[p+1];
}
inline int swap_b(int start, int a, int b)
{
	int m,n;
	int end = start;
	a = 8-a;
	b = 8-b;
	if( a < b)
		swap(a,b);
	if( a != b )
	{
		m = extract(start,a);
		n = extract(start,b);
		end = start-m-n+m/base10[a-b]+n*base10[a-b];
	}
	return end;
}

bool inside(int a, int b, int x, int y)
{
	return (a >= 0 && a < x && b >=0 && b < y);
}
int cantor_expand(int start)
{
	int i,j,result,t;
	int digit[9];
	for( i = 0; i < 9; i++ )
	{
		digit[i] = start%10;
		start /= 10;
	}
	for( result = i = 0; i < 9; i++ )
	{
		for( j = t = 0; j < i; j++ )
			if( digit[j] < digit[i] )
				t++;
		result += t*factor[i];
	}
	return result;
}
void get_input(char* line,int& start,int& x,int& y)
{
	char* p = line;
	int i = 0;
	start = 0;
	while( *p != '\0' && i < 9 )
	{
		if( *p == 'x' )
		{
			x = i/3;
			y = i%3;
			p++;
			i++;
		}
		else if( *p >= '1' && *p <= '8')
		{
			start += (*p-'0')*base10[8-i];
			p++;
			i++;
		}
		else
			p++;
	}
}



int make_index(int start, int x, int y)
{
	int a,b,i,m,n,r,next,u,ri,rp;
	pair<int,int>item;
	queue<pair<int,int> >Q;
	memset(&nodes,0,sizeof(nodes));

	r = cantor_expand(start);
	nodes[r].taken = true;
	nodes[r].parent = -1;
	
	u = ((r<<8)|(x*3+y));
	Q.push(make_pair(start,u));

	while( Q.empty() != true )
	{
		item = Q.front();
		Q.pop();
		ri = (item.second >> 8);
		rp = (item.second&0xff);
		x = rp/3;
		y = rp%3;

		for( i = 0; i < 4; i++ )
		{
			a = x+step[i][0];
			b = y+step[i][1];
			if( inside(a,b,3,3) != true )
				continue;
			m = a*3+b;
			next = swap_b(item.first,rp,m);
			n = cantor_expand(next);
			if( nodes[n].taken == true )
				continue;
			nodes[n].parent = ri;
			nodes[n].taken = true;
			nodes[n].letter = direction[i];

			u = ((n<<8)|m);
			Q.push(make_pair(next,u));
		}
	}
	return r;
}
int main()
{
	int x,y,n,r;
	int start;
	char input[128];
	r = make_index(123456780,2,2);
	while( gets(input) != NULL )
	{

		get_input(input,start,x,y);
		n = cantor_expand(start);
		if( nodes[n].taken != true )
			printf("unsolvable\n");
		else
		{
			while( n != r )
			{
				putchar(nodes[n].letter);
				n = nodes[n].parent;
			}
			putchar('\n');
		}
	}
	return 0;
}