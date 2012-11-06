#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int test_case;
	vector< pair<string,string> >rule;
	pair<string,string> temp;
	string target;
	cin >> test_case;
	while( test_case != 0 )
	{
		getline(cin, target );
		target.clear();
		for( int i = 0; i < test_case; i++ )
		{
			getline( cin ,temp.first);
			getline( cin ,temp.second);
			rule.push_back( temp );
		}

		getline( cin,target );
		for( size_t i = 0;i < rule.size(); i++ )
		{
			size_t pos;
			while( (pos = target.find( rule[i].first ) ) != string::npos )
				target.replace( target.begin()+pos,
						target.begin()+pos+rule[i].first.size(),
							rule[i].second );
		}
		cout << target << endl;
		cin >> test_case;
		target.clear();
		rule.clear();
	}
	return 0;
}
