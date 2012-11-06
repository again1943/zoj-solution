#include<cstdio>
#include<utility>
#include<bitset>
#include<algorithm>
using namespace std;
#define MAX_ELEN 5001

bitset<MAX_ELEN>bit_set;
pair<int,int> elem[MAX_ELEN];

struct sort_t
{
	bool operator()(const pair<int,int>& a,const pair<int,int>& b)
	{
		if (a.first < b.first)
			return true;
		else if( a.first > b.first )
			return false;
		else
			return a.second < b.second;
	}
};
int do_work( pair<int,int>* elem, int n )
{
	int i,j;
	int last;
	int time;
	bit_set.set();	
	sort(elem,elem+n,sort_t());
	for( i = time = 0; i < n; i++ )
	{
		if( bit_set[i] == true )
		{
			time++;
			bit_set[i] = false;
			last = elem[i].second;
			for( j = i+1; j < n; j++ )
			{
				if( bit_set[j] == true && elem[j].second >= last )
				{
					bit_set[j] = false;	
					last = elem[j].second;
				}
			}
		}
	}
	return time;
}
int main()
{
	int test_case,t,i,n;
	scanf("%d",&test_case);
	for( t = 0; t < test_case; t++ )
	{
		scanf("%d",&n);
		for( i = 0; i < n; i++ )
			scanf("%d%d",&elem[i].first,&elem[i].second);
		printf("%d\n",do_work(elem,n));
	}
	return 0;
}

