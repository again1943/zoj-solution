#include <cstdio>
#include <string>
#include <set>
#include <iostream>
#include <utility>
using namespace std;

int main()
{
	int n,m,i,t,s;
	string word;
	
	set<string> keywords;
	cin >> n;
	for( i = 0; i < n; i++ )
	{
		cin >> word;
		keywords.insert(word);
	}
	cin >> n;
	for( i = 0; i < n; i++ )
	{
		cin >> m;
		for( t = s = 0; t < m; t++ )
		{
			cin >> word;
			if( keywords.find(word) != keywords.end() )
				s++;
		}
		cout << s << endl;
	}
	//system("pause");
	return 0;
}