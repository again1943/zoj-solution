#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXN 8
int house[MAXN][MAXN];
int status[MAXN][MAXN][MAXN][MAXN];
int step[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

bool inside(int w, int h, int x, int y)
{
	return (x >= 0 && x < h && y >= 0 && y < w);
}
inline int mkitem(int a,int b, int c, int d)
{
	int item = (((a&0xff) << 24)|((b&0xff) << 16)|((c&0xff) << 8)|(d&0xff));
	return item;
}
inline void getitem(int item,int& a, int& b, int& c, int& d)
{
	a = ((item >> 24)&0xff);
	b = ((item >> 16)&0xff);
	c = ((item >> 8)&0xff);
	d = (item&0xff);
}
struct queue_item_t
{
	int pos;
	int step;
};

struct sort_op_t
{
	bool operator()(const queue_item_t& a, const queue_item_t& b)
	{
		return a.step > b.step;
	}
};
int cargo_search(int w,int h, int wx,int wy, int cx, int cy, int gx, int gy)
{
	int i,x1,y1,x2,y2,x,y,px,py;
	queue_item_t item;
	priority_queue<queue_item_t,vector<queue_item_t>,sort_op_t>Q;
	memset(status,-1,sizeof(status));
	status[wx][wy][cx][cy] = 0;
	item.pos = mkitem(wx,wy,cx,cy);
	item.step = 0;
	Q.push(item);

	while( Q.empty() != true )
	{
		item = Q.top();
		Q.pop();
		getitem(item.pos,x1,y1,x2,y2);
		if( abs(x1-x2)+abs(y1-y2) == 1 )
		{
			if( x1 == x2 )
			{
				x = px = x1;
				py = y2;
				y = (y1 < y2)?y2+1:y2-1;
			}
			else
			{
				y = py = y1;
				px = x2;
				x = (x1<x2)?x2+1:x2-1;
			}
			if( x == gx && y == gy )
				return status[x1][y1][x2][y2]+1;
			if( inside(w,h,x,y) && house[x][y] != 1 && status[px][py][x][y] == -1 )
			{
				status[px][py][x][y] = status[x1][y1][x2][y2]+1;
				item.pos = mkitem(px,py,x,y);
				item.step = status[px][py][x][y];
				Q.push(item);
			}
		}
		for(i = 0; i < 4; i++ )
		{
			x = x1+step[i][0];
			y = y1+step[i][1];
			

			if( inside(w,h,x,y) != true ||
				house[x][y] == 1 || 
				(x == x2 && y == y2) ||
				status[x][y][x2][y2] >= 0 )
				continue;
			status[x][y][x2][y2] = status[x1][y1][x2][y2];
			item.pos = mkitem(x,y,x2,y2);
			item.step = status[x][y][x2][y2];
			Q.push(item);
		}
	}
	return -1;
}
int main()
{
	int w,h,i,j,cx,cy,gx,gy,wx,wy;
	while( scanf("%d%d",&w,&h) && w != 0 )
	{
		memset(house,0,sizeof(house));
		//memset(status,0,sizeof(status));
		for( i = 0; i < h; i++ )
		for( j = 0; j < w; j++ )
		{
			scanf("%d",&house[i][j]);
			if( house[i][j] == 2 )
			{
				cx = i;
				cy = j;
				house[i][j] = 0;
			}
			else if( house[i][j] == 3 )
			{
				gx = i;
				gy = j;
				house[i][j] = 0;
			}
			else if( house[i][j] == 4 )
			{
				wx = i;
				wy = j;
				house[i][j] = 0;
			}
			else
				continue;
		}
		printf("%d\n",cargo_search(w,h,wx,wy,cx,cy,gx,gy));
	}
	return 0;
}
