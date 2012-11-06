#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
int degree( const string line )
{
	int dge = 0;
	for( size_t i = 0; i < line.size(); i++ )
		for( size_t j = i; j < line.size(); j++ )
			if( line[i] > line[j] )
				dge++;
	return dge;
}

struct sort_op
{
	bool operator()( pair<string,int>first, pair<string,int>second )
	{
		return first.second < second.second;
	}
};
int main()
{
	int test_case;
	int num,len;
	pair<string,int>temp;
	vector<pair<string,int> > DNA;
	cin >> test_case;
	getchar();
	cin >> num >> len;
	for( int j = 0; j < len; j++ )
	{
		cin >> temp.first;
		temp.second = degree( temp.first );
		DNA.push_back( temp );
		temp.first.clear();
	}
	stable_sort( DNA.begin(),DNA.end(),sort_op() );
	for( int j = 0; j < len; j++ )
		cout << DNA[j].first << endl;
	getchar();
	DNA.clear();
	for( int i = 1; i < test_case; i++ )
	{
		cin >> num >> len;
		cout << endl;
		for( int j = 0; j < len; j++ )
		{
			cin >> temp.first;
			temp.second = degree( temp.first );
			DNA.push_back( temp );
			temp.first.clear();
		}
		stable_sort( DNA.begin(),DNA.end(),sort_op() );
		for( int j = 0; j < len; j++ )
			cout << DNA[j].first << endl;
		DNA.clear();
		getchar();
	}
	return 0;
}
