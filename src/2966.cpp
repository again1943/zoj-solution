#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

#define MAX_NODE 512
unsigned int matrix[MAX_NODE][MAX_NODE];

struct com_t
{
	bool operator()(const pair<unsigned int, unsigned int> &a, const pair<unsigned int, unsigned int>& b)
	{
		return a.second > b.second;
	}
};
unsigned int mst(unsigned int matrix[][MAX_NODE],int n)
{
	int setcnt,i;
	unsigned int ret;
	bool touched[MAX_NODE];
	pair<unsigned int, unsigned int> item;
	priority_queue<pair<unsigned int ,unsigned int>,vector<pair<unsigned int, unsigned int> >, com_t>Q;

	memset(touched,false,sizeof(touched));
	setcnt = 1;
	ret = 0;
	touched[0] = true;
	for( i = 1; i < n; i++ )
		Q.push(make_pair(i,matrix[0][i]));
	while( setcnt != n )
	{
		item = Q.top();
		Q.pop();
		if( touched[item.first] == true )
			continue;
		setcnt += 1;
		ret += item.second;
		touched[item.first] = true;
		for( i = 0; i < n; i++ )
			if( touched[i] != true )
				Q.push(make_pair(i,matrix[item.first][i]));
	}
	return ret;
}
int main()
{
	int t,n,e,i,x,y,v,k;
	//freopen("data.txt","r",stdin);
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		memset(matrix,-1,sizeof(matrix));
		scanf("%d%d",&n,&e);
		for( i = 0; i < e; i++ )
		{
			scanf("%d%d%d",&x,&y,&v);
			matrix[x][y] = matrix[y][x] = v;
		}
		printf("%d\n",mst(matrix,n));
	}
	return 0;
}