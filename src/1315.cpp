#include<set>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
#define EXCUSE_CNT 24
struct excuse_t
{
	int occurs;		
	string excuse;
	excuse_t():occurs(0),excuse()
	{}
	excuse_t(string exc ):occurs(0),excuse(exc)
	{}
};
vector<excuse_t> vec;
set<string>key;

void parse_word( excuse_t& ext )
{
	char c;
	size_t i;
	string word;			
	for( i = 0; i < ext.excuse.size(); i++ )
	{
		c = ext.excuse[i];
		if( (c >= 'a'&& c <= 'z')||(c >= '0' && c <= '9'))	
			word.push_back(c);
		else if( c >= 'A' && c <= 'Z' )
			word.push_back(c-'A'+'a');
		else
		{
			if( word.size() != 0 && key.find(word) != key.end())	
				ext.occurs += 1;
			word.clear();
		}
	}
	if( word.size() != 0 && key.find(word) != key.end())
		ext.occurs += 1;
}
int main()
{
	size_t idx,maxidx;
	int n,k,i;
	int t = 0;
	string word,line;
	while( cin >> n >> k )
	{
		for( i = 0; i < n; i++ )	
		{
			cin >> word;
			key.insert(word);
		}
		getchar();
		for( i = 0,maxidx = 0; i < k; i++ )
		{
			getline(cin,line);			
			vec.push_back(excuse_t(line));	
			idx = vec.size()-1;
			parse_word(vec[idx]);
			if(vec[maxidx].occurs < vec[idx].occurs  )
				maxidx = idx;
		}
		cout << "Excuse Set #" << ++t << endl;
		for( idx = 0; idx < vec.size(); idx++ )
			if(vec[idx].occurs == vec[maxidx].occurs )
				cout << vec[idx].excuse << endl;
		cout << endl;
		vec.clear();
		key.clear();
	}
	return 0;
}

