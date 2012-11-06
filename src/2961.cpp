#include <queue>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define MAX_BUTTON 128
#define MAX_STATE 1000000

bool state[MAX_STATE];
int button[MAX_BUTTON];
int track[MAX_STATE];
int result[MAX_BUTTON];

int multi[] = {1,10,100,1000,10000,100000,1000000,10000000};
int next( int s, int o, int d)
{
	int i;
	int n = 0;
	int b = multi[d-1];
	for( i = 0; i < d; i++ )
	{
		n += ((s/b+o/b)%10)*b;
		s %= b;
		o %= b;
		b /= 10;
	}
	return n;
}

int prev( int e, int o, int d )
{
	int i;
	int n = 0;
	int b = multi[d-1];
	for( i = 0; i < d; i++ )
	{
		n += ((e/b-o/b+10)%10)*b;
		e %= b;
		o %= b;
		b /= 10;
	}
	return n;
}
bool bfs( int m, int n, int s, int e )
{
	int i,t,item;
	std::queue<int>Q;
	Q.push(s);
	track[s] = -1;

	while( Q.empty() != true )
	{
		item = Q.front();
		Q.pop();
		for( i = 0; i < n; i++ )
		{
			t = next(item,button[i],m);
			if( t == e)
			{
				track[t] = button[i];
				return true;
			}
			if( state[t] != true )
			{
				state[t] = true;
				Q.push(t);
				track[t] = button[i];
			}
		}
	}
	return false;
}
inline void put( int n, int d )
{
	int i;
	for( i = d-1; i >= 0 ; i-- )
	{
		putchar(n/multi[i]+'0');
		n %= multi[i];
	}
	putchar('\n');
}
void print( int s, int e, int d )
{
	int p = e;
	int idx = 0;
	result[idx++] = track[p];
	while( ( p = prev(p,track[p],d)) != s )
		result[idx++] = track[p];
	printf("%d\n",idx);
	for( int i = idx-1; i >= 0; i-- )
		put(result[i],d);
}
int main()
{
	//char word[16];
	int d,n,i,s,e;

	while( scanf("%d%d",&d,&n) != -1 )
	{
		for( i = 0; i < n; i++ )
			scanf("%d",&button[i]);
		scanf("%d%d",&s,&e);
		std::sort(button,button+n);
		memset(state,false,sizeof(state));
		if( s == e )
			printf("0\n");
		else if( bfs(d,n,s,e) == false )
			printf("-1\n");
		else
			print(s,e,d);
	}
	return 0;
}
