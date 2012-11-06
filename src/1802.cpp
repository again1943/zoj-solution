#include<cstdio>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
#define ADJ_CNT 4
#define COLOR_CNT 16
#define POINT_COUNT 12
struct point_t
{
	double x,y;
}points[POINT_COUNT];

struct graph
{
	int adj_cnt;
	int color;
	int adj_pt[ADJ_CNT];
	bitset<COLOR_CNT> color_bit;
}G[POINT_COUNT];

inline double dist( const point_t& a,const point_t& b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int total_color;
int colors[COLOR_CNT] = {1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31};

void dfs(graph* G, int n, int current )
{
	int i,j,idx,color;
	for( i = 0; i < COLOR_CNT && G[current].color_bit[i]==false; i++);
	color = colors[i];
	total_color = max(total_color,i+1);
	G[current].color_bit[i] = false;
	G[current].color = color;
	for(j = 0; j < G[current].adj_cnt; j++ )
	{
		idx = G[current].adj_pt[j];	
		if( G[idx].color < 0 )
			G[idx].color_bit[i] = false;
	}
	for( j = 0; j < G[current].adj_cnt; j++ )
	{
		idx = G[current].adj_pt[j];
		if( G[idx].color < 0 )
			dfs(G,n,idx);	
	}
}

int main()
{
	int i,j,n;
	int t = 0;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )
		{
			scanf("%lf%lf",&points[i].x,&points[i].y);
			G[i].color_bit.set();			
			G[i].adj_cnt = 0;
			G[i].color = -1;
			for( j = 0; j < i; j++ )
			{
				if( dist(points[i],points[j]) <= 20 )
				{
					G[i].adj_pt[G[i].adj_cnt++] = j;	
					G[j].adj_pt[G[j].adj_cnt++] = i;
				}
			}
			
		}
		total_color = 0;
		dfs(G,n,0);
		printf("The towers in case %d can be covered in %d frequencies.\n",++t,total_color);
	}
	return 0;
}
