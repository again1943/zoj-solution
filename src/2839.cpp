#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;
#define MAXN 3000

int candidate[MAXN];

bool find_seq(int a, int b,int c, int n, pair<int,int>& ret)
{
	int i,d;
	for( i = 1,d = b; i <= n-2; i++ )
	{
		d = d+(b-a);
		if( binary_search(candidate,candidate+c,d) != true )
			return false;
	}
	ret.first = a;
	ret.second = b-a;
	return true;
}

struct pair_sort_t
{
	bool operator()(const pair<int,int>& a, const pair<int,int>& b)
	{
		if( a.second < b.second )
			return true;
		if( a.second > b.second )
			return false;
		return a.first < b.first;
	}
};
int main()
{
	int m,n,i,j,t,k;
	pair<int,int>item;
	vector<pair<int,int> >vec;

	k = 0;
	while(scanf("%d%d",&n,&m) && n != 0)
	{
		t = 0;
		for( i = 0; i <=m; i++ )
		for( j = i; j <=m; j++ )
			candidate[t++] = i*i*i+j*j*j;
		sort(candidate,candidate+t);
		t = unique(candidate,candidate+t)-candidate;
		for( i = 0; i < t; i++ )
		for( j = i+1; j < t; j++ )
			if( find_seq(candidate[i],candidate[j],t,n,item) == true )
				vec.push_back(item);
		if( k != 0 )
			printf("\n");
		printf("Case %d:\n",++k);
		if( vec.size() == 0 )
			printf("NONE\n");
		else
		{
			sort(vec.begin(),vec.end(),pair_sort_t());
			for( i = 0; i < (int)vec.size(); i++ )
				printf("%d %d\n",vec[i].first,vec[i].second);
			vec.clear();
		}
	}
	return 0;
}