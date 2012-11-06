#include<cstdio>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;
#define MAXN 124
int lock[MAXN];
bool state[MAXN][MAXN];

struct state_t
{
	int x,y,t;
	state_t():x(0),y(0),t(0)
	{}
	state_t(int _x, int _y, int _t):x(_x),y(_y),t(_t)
	{}
};
inline int adv( int i, int n)
{
	return (i+lock[i])%n;
}
inline int bak( int i, int n)
{
	return (i+n-lock[i])%n;
}
inline int actionx(queue<state_t>&Q,int act, int n,int x, int y,int t)
{
	if( act == 0 )
		x = adv(x,n);
	else
		x = bak(x,n);
	if( x == y )
		return t+1;
	if( state[x][y] != true )
	{
		Q.push(state_t(x,y,t+1));
		state[x][y] = true;
	}
	return -1;
}
inline int actiony(queue<state_t>&Q, int act, int n, int x, int y, int t)
{
	if( act == 0 )
		y = adv(y,n);
	else
		y = bak(y,n);
	if( x == y )
		return t+1;
	if( state[x][y] != true )
	{
		Q.push(state_t(x,y,t+1));
		state[x][y] = true;
	}
	return -1;
}
int bfs(int n, int x, int y)
{
	int ret;
	state_t s;
	queue<state_t>Q;
	if(x == y)
		return 0;
	memset(state,false,sizeof(state));
	state[x][y] = true;
	Q.push(state_t(x,y,0));
	
	while( Q.empty() != true )
	{
		s = Q.front();
		Q.pop();
		if( (ret = actionx(Q,0,n,s.x,s.y,s.t)) >= 0)
			return ret;
		if( (ret = actionx(Q,1,n,s.x,s.y,s.t)) >= 0)
			return ret;
		if( (ret = actiony(Q,0,n,s.x,s.y,s.t)) >= 0)
			return ret;
		if( (ret = actiony(Q,1,n,s.x,s.y,s.t)) >= 0)
			return ret;
	}
	return -1;
}
int main()
{
	int n,i,x,y,ret;
	while( scanf("%d",&n) && n != 0 )
	{
		for(i = 0; i < n; i++)
			scanf("%d",&lock[i]);
		scanf("%d%d",&x,&y);
		if( (ret = bfs(n,x,y)) >= 0 )
			printf("open it on the %dth move!\n",ret);
		else
			printf("Lara is traped!\n");
	}
	return 0;
}