#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<vector>
#include<cstdio>
using namespace std;

bool word_char( char& c )
{
	if( c >= '0' && c <= '9' )
		return true;
	if( c >= 'a' && c <= 'z' )
		return true;
	if( c >= 'A' && c <= 'Z' )
	{
		c = c-'A'+'a';
		return true;
	}
	return false;
}

int main()
{
	char c;
	string word;	
	int freq = 0;
	vector<string>max_str;
	map<string,int>word_dict;	
	map<string,int>::iterator pos;

	while( ( c = getchar() ) != -1 )
	{
		if( word_char(c) == true )
			word.push_back(c);
		else
		{
			if( word.size() == 0 )
				continue;
			if( (pos = word_dict.find(word)) != word_dict.end())
			{
				pos->second++;
				if( pos->second == freq )
					max_str.push_back(pos->first);
				if( pos->second > freq )
				{
					max_str.clear();
					max_str.push_back(pos->first);
					freq = pos->second;
				}
			}
			else
			{
				word_dict.insert(make_pair(word,1));
				if( freq <= 1 )
				{
					max_str.push_back(word);	
					freq = 1;
				}
			}
			word.clear();
		}
	}
	sort(max_str.begin(),max_str.end());
	printf("%d occurrences\n",freq);
	for( size_t i = 0; i < max_str.size(); i++ )
		printf("%s\n",max_str[i].c_str());
	return 0;
}
