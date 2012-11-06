#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<string> vec;

bool find_str( string& sub_str )
{
	int j;
	int n = vec.size();
	for( j = 1; j < n; j++ )
	{
		if( vec[j].find(sub_str) != string::npos ) 
			continue;
		reverse(sub_str.begin(),sub_str.end());
		if( vec[j].rfind(sub_str) != string::npos )
			continue;
		return false;
	}
	return true;
}
int do_work()
{
	int L,i;
	int n = vec.size();
	int len = vec[0].size();
	string sub_str;
	
	for( L = len; L >= 1; L-- )
	for( i = 0; i + L -1 < len; i++ )
	{
		sub_str = vec[0].substr(i,L);	
		if( find_str(sub_str) == true )		
			return L;
	}
	return 0;
}

struct sort_t
{
	bool operator()(const string& x, const string& y )
	{
		return x.size() < y.size();
	}
};
int main()
{
	string name;
	int test_case;
	int i,t,n;
	cin >> test_case;
	for( t = 0; t < test_case; t++ )
	{
		cin >> n;
		for( i = 0; i < n; i++ )
		{
			cin >> name;
			vec.push_back(name);
		}
		sort(vec.begin(),vec.end(),sort_t());
		cout << do_work() << endl;
		vec.clear();
	}
	return 0;
}
