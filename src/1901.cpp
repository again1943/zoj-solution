#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#define MAX_NODE 128
#define MAX_LIM 10000

int step[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
struct point_t
{
        int x,y;
}point[MAX_NODE];

inline double dist( int x0, int y0, int x1, int y1 )
{
        return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}

void dfs(int n, int x, int y, double& m)
{
        int i;
        double t = 0;
        for( i = 0; i < n; i++ )
                t += dist(x,y,point[i].x,point[i].y);
        if( m > t )
        {
                m = t;
                for( i = 0; i < 4; i++ )
                        dfs(n,x+step[i][0],y+step[i][1],m);
        }
}
int main()
{
        int n,i;
        double result;
        while( scanf("%d",&n) != -1 )
        {
                for( i = 0; i < n; i++ )
                        scanf("%d%d",&point[i].x,&point[i].y);
                result = 1e100;
                dfs(n,MAX_LIM/2,MAX_LIM/2,result);
                printf("%d\n",(int)nearbyint(result));
        }
        return 0;
}
