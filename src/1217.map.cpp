#include <map>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <queue>
//#include <string>

using namespace std;

#define MAX_ELEM 340000
pair<char,int> nodes[MAX_ELEM];
map<int,int> M;

int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

char direction[] =  {'d','u','r','l'};

int base10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

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

void make_index(int start, int x, int y)
{
	int nrnodes = 0;
	int i,n,a,b,s,next;
	pair<int,int>item;
	map<int,int>::iterator iter;
	queue<pair<int,int> > Q;
	M.insert(make_pair(start,nrnodes));
	nodes[0].second = -1;

	Q.push(make_pair(start,x*3+y));

	while( Q.empty() != true )
	{
		item = Q.front();
		Q.pop();

		for( i = 0; i < 4; i++ )
		{
			a = item.second/3+step[i][0];
			b = item.second%3+step[i][1];
			if( inside(a,b,3,3) != true )
				continue;
			s = a*3+b;
			next = swap_b(item.first,item.second,s);
			if( (iter = M.find(next)) != M.end() )
				continue;
			n = ++nrnodes;
			M.insert(make_pair(next,n));//record next with index n
			Q.push(make_pair(next,s));
			nodes[n].first = direction[i];//set operation
			nodes[n].second = item.first;//set parent
		}
	}
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

int main()
{
	int x,y,n;
	int start, target;
	map<int,int>::iterator iter;
	char input[128];
	
	target = 123456780;
	make_index(target,2,2);
	while( gets(input) != NULL )
	{

		get_input(input,start,x,y);
		if((iter = M.find(start)) == M.end())
			printf("unsolvable\n");
		else
		{
			n = iter->second;
			while( n > 0 )
			{
				putchar(nodes[n].first);
				n = M[nodes[n].second];
			}
			putchar('\n');
		}
	}
	return 0;
}