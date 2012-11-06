#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <iostream>
#include <algorithm>
#define MAX_RULE 20004
using namespace std;
map<string,int> rule;
vector<string> vec[MAX_RULE];

int main()
{
	char c;
	string name;
	int n,m,t,k,i,cnt,order,maxorder;
	cin >> t;
	for( k = 0; k < t; k++ )
	{
		cnt = maxorder = -1;
		cin >> n;
		for( i = 0; i < n; i++ )
		{
			cin >> name >> order;
			rule.insert(make_pair(name,order+10000));
		}
		cin >> m;
		for( i = 0; i < m; i++ )
		{
			cin >> c;
			switch( c )
			{
			case 'a':
				cin >> name;
				order = rule[name];
				vec[order].push_back(name);
				maxorder = max(maxorder,order);
				break;
			case 'g':
				if( maxorder < 0 )
					name = "<empty>";	
				else
				{
					name = vec[maxorder].back();
					vec[maxorder].pop_back();
					while( maxorder >= 0 && vec[maxorder].size() == 0 )
						maxorder -= 1;
				}
				cout << name << endl;
				break;
			default:
				cin >> name;
				order = rule[name];
				vector<string>::iterator it = find(vec[order].begin(),vec[order].end(),name);
				vec[order].erase(it);
				if( maxorder == order )
					while( maxorder >= 0 && vec[maxorder].size() == 0 )
						maxorder -= 1;
				break;
			}
		}
		rule.clear();
		for( i = 0; i < MAX_RULE; i++ )
			vec[i].clear();
	}
	return 0;
}
