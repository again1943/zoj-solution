#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

int main()
{
	int n,m;	
	int result;
	int elem;
	int size;
	bool flag;
	vector<int>vec;
	vector<pair<int,bool> >total;
	while( scanf("%d%d",&n,&m) != -1 )
	{
		for( int i = 0; i < n; i++ )	
		{
			scanf("%d",&elem);	
			size_t j;
			for( j = 0; j < vec.size(); j++ )
			{
				if( elem % vec[j] == 0 )
					break;
				if( vec[j] % elem == 0 )
				{
					vec[j] = elem;
					break;
				}
			}
			if( j == vec.size())
				vec.push_back(elem);
		}
		for( size_t i = 0; i < vec.size(); i++ )			
		{
			total.push_back(make_pair(vec[i],true));
			size = total.size();
			for( int j = 0; j < size-1; j++ )
			{
				flag = !total[j].second;
				total.push_back(make_pair(vec[i]*total[j].first,flag));
			}
		}
		result = 0;
		for( size_t i = 0; i < total.size(); i++ )
		{
			if( total[i].second == true )
				result += m/total[i].first;
			else
				result -= m/total[i].first;
		}
		printf("%d\n",result);
		vec.clear();
		total.clear();
	}
	return 0;

}
