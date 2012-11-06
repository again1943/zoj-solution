#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX_PROBLEM 100004
#define MAX_NUM	10004
int problem[MAX_PROBLEM];
vector<int> values[MAX_NUM];


int solve(int n, int m, int p)
{
	size_t t;
	int i,*pos,*last,*item;
	int result = p;
	priority_queue<int> Q;
	sort(problem,problem+n);


	for( i = 0,last = problem; i < m; i++ )
	{
		pos = upper_bound(problem,problem+n,result);
		for( item = last; item < pos; item++ )
		{
			for( t = 0; t < values[*item].size(); t++ )
				Q.push(values[*item][t]);
		}
		if( Q.empty() == true )
			return result;
		result += Q.top();
		Q.pop();
		last = pos;
	}
	return result;
}
int main()
{
	int n,m,i,p,b,a,total;

	//freopen("a.txt","r",stdin);
	while(scanf("%d%d%d",&n,&m,&p) != -1)
	{
		for( i = 0; i < MAX_NUM; i++ )
			values[i].clear();
		for( i = 0,total = 0; i < n; i++ )
		{
			scanf("%d%d",&a,&b);
			if( values[a].size() == 0 )
				problem[total++] = a;
			values[a].push_back(b);	
		}
		printf("%d\n",solve(total,m,p));
	}
	return 0;
}