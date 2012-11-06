#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;
#define MAXN 	5008
#define EPS		1e-16
#define INF		-1e20

struct line_t
{
	double k,b;	
}lines[MAXN];

struct ray_t
{
	double k,b,x;
}stack[MAXN];

struct std_sort_t
{
	bool operator()(const line_t& a, const line_t& b)
	{
		if( abs(a.k-b.k) < EPS )	
			return a.b > b.b;
		return a.k < b.k;
	}
};

int color_rainbow(int n)
{
	int i;
	double px;
	int top = 0;
	
	stack[top].k = lines[0].k;
	stack[top].b = lines[0].b;
	stack[top].x = INF;

	for( i = 1; i < n; i++ )	
	{
		if( abs(stack[top].k-lines[i].k) < EPS )
			continue;
		do{
			px = (lines[i].b-stack[top].b)/(stack[top].k-lines[i].k);
			if( px-stack[top].x > EPS )
				break;
			top -= 1;
		}while( top >= 0 );
		top += 1;
		stack[top].k = lines[i].k;
		stack[top].b = lines[i].b;
		stack[top].x = (top==0?INF:px);
	}
	return top+1;
}
int main()
{
	int k,i,t,n;			
	scanf("%d",&k);
	for( t = 0; t < k; t++ )
	{
		scanf("%d",&n);
		for( i = 0; i < n; i++ )
			scanf("%lf%lf",&lines[i].k,&lines[i].b);
		sort(lines,lines+n,std_sort_t());
		printf("%d\n",color_rainbow(n));
	}
	return 0;
}
