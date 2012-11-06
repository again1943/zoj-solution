#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>

#define MAX_ELEM 1024
using namespace std;

map<int,int>order;
int series[MAX_ELEM];

//bsearch()
int max_series(int n)
{
	int i,j,size,next,seslen,step;
	int maxlen = 1;
	vector<int> vec;
	map<int,int>::iterator item;
	for( item = order.begin(); item != order.end(); ++item )
	{
		vec.push_back(item->first);
		maxlen = max(maxlen,item->second);
	}
	size = vec.size();
	for(i = 0; i < size; i++ )
	{
		for( j = i+1; j < size; j++ )
		{
			if( size-j+3 < maxlen )
				break;
			seslen = 2;
			step = vec[j]-vec[i];
			next = vec[j]+step;
			/*while(binary_search(vec.begin()+j+1,vec.end(),next) == true )
			{
				seslen += 1;
				next += step;
			}*/
			while((item = order.find(next)) != order.end())
			{
				seslen += 1;
				next += step;
			}
			maxlen = max(seslen,maxlen);
		}

	}
	return maxlen;
}
int main()
{
	int n,i;
	map<int,int>::iterator item;
	while(scanf("%d",&n) != -1)
	{
		for( i = 0; i < n; i++ )
		{
			scanf("%d",&series[i]);
			if( (item = order.find(series[i])) != order.end() )
				item->second += 1;
			else
				order.insert(make_pair(series[i],1));
		}
		printf("%d\n",max_series(n));
		order.clear();
	}
	return 0;
}