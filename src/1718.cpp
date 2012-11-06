#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
using namespace std;
#define MAX_POINT 128
struct cell_t
{
	double x,y,z,r;
}cells[MAX_POINT];

bool mask[MAX_POINT];
double matrix[MAX_POINT][MAX_POINT];

inline double dist( cell_t& a,cell_t& b )
{
	double d = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
	return ((d > a.r+b.r)?(d-a.r-b.r):0);
}

struct comp_t
{
	bool operator()(const pair<int,int>& a, const pair<int,int>& b )
	{
		return matrix[a.first][a.second] > matrix[b.first][b.second];	
	}
};

double mst( int n )
{
	int i,idx;
	pair<int,int>item;
	priority_queue<pair<int,int>,vector<pair<int,int> >,comp_t>Q;

	int count = 1;
	double total = 0;

	memset(	mask,0,sizeof(mask));	
	mask[0] = true;

	for( i = 1; i < n; i++ )
		Q.push(make_pair(0,i));

	while( count != n )
	{
		item = Q.top();	
		Q.pop();
		if( mask[item.first] == true && mask[item.second] == true )
			continue;
		total += matrix[item.first][item.second];	
		count += 1;
		idx = (!mask[item.first]?item.first:item.second);
		mask[idx] = true;
		for( i = 0; i < n; i++ )
			if( idx != i && mask[i] != true )	
				Q.push(make_pair(idx,i));
	}
	return total;
}
int main()
{
	int n,i,j;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = 0; i < n; i++ )	
		{
			scanf("%lf%lf%lf%lf",&cells[i].x,
				&cells[i].y,&cells[i].z,&cells[i].r);	
			matrix[i][i] = 0;
			for( j = 0; j < i; j++ )
				matrix[i][j] = matrix[j][i] = dist(cells[j],cells[i]);
		}
		printf("%0.3lf\n",mst(n));	
	}
	return 0;
}
