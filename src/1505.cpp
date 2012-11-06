#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<algorithm>
#include<utility>
using namespace std;

int trans[4][2] = 
{
	{0,1},{0,-1},{1,0},{-1,0}
};
int makestate( int* hold)
{
	int i,ret;
	for( i = ret = 0; i < 4; i++ )
		ret |= (hold[i]<<(i*8));
	return ret;
}
void makehold(int* x, int* y, int* hold)
{
	int i;
	for( i = 0; i < 4; i++)
		hold[i] = x[i]*8+y[i];
	sort(hold,hold+4);
}
void decodestate(int state,int* hold)
{
	int i;
	for( i = 0; i < 4; i++ )
		hold[i] = ((state&(0xff<<(i*8)))>>(i*8));
}
bool inside( int n, int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < n);
}
bool takeplace(int x1, int y1, int* x, int* y)
{
	int i;
	for( i = 0; i < 4; i++)
		if( x1 == x[i] && y1 == y[i])
			return true;
	return false;
}
bool bfs( int start, int end, int depth)
{
	int hold[4],x[4],y[4],i,j,x1[4],y1[4],state;
	set<int>S;	
	pair<int,int>item;
	queue<pair<int,int> >Q;
	S.insert(start);
	Q.push(make_pair(start,0));
	while( Q.empty() != true )
	{
		item = Q.front();
		Q.pop();
		if(item.first == end)
			return true;
		decodestate(item.first,hold);
		//now the the for (x,y) of four pieces
		for( i = 0; i < 4; i++ )
		{
			x[i] = hold[i]/8;
			y[i] = hold[i]%8;
		}
		//let's move!
		memcpy(x1,x,sizeof(x));
		memcpy(y1,y,sizeof(y));
		for( i = 0; i < 4; i++ )//four pieces 
		{
			for( j = 0; j < 4; j++ )//four directions
			{
				x1[i] = x[i]+trans[j][0];	
				y1[i] = y[i]+trans[j][1];
				if( takeplace(x1[i],y1[i],x,y) == true )	
				{
					x1[i] += trans[j][0];
					y1[i] += trans[j][1];
				}
				if( inside(8,x1[i],y1[i]) == true && 
					takeplace(x1[i],y1[i],x,y) != true )//valid move
				{
					makehold(x1,y1,hold);
					state = makestate(hold);
					if( S.find(state) == S.end() && item.second < 8 )//net state within 8 steps
					{
						S.insert(state);
						Q.push(make_pair(state,item.second+1));
					}
				}
			}
			x1[i] = x[i];
			y1[i] = y[i];
		}
	}
	return false;
}
int main()
{
	int hold[4];
	int x,y,start,end,i;
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&x,&y) != -1)
	{
		start = end = 0;
		hold[0] = (x-1)*8+(y-1);
		for(i = 1; i < 4; i++ )
		{
			scanf("%d%d",&x,&y);
			hold[i] = (x-1)*8+(y-1);
		}
		sort(hold,hold+4);
		start = makestate(hold);
		for( i = 0; i < 4; i++ )
		{
			scanf("%d%d",&x,&y);
			hold[i] = (x-1)*8+(y-1);
		}
		sort(hold,hold+4);
		end = makestate(hold);
		if( bfs(start,end,8) == true )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
