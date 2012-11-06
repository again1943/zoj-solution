#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct comp_t
{
	bool comp(const string& first,const string& second)
	{
		size_t len = first.size();
		for( size_t i = 0; i < len; i++ )
		{
			if( first[i] < second[i])
				return true;
			if( first[i] > second[i])
				return false;
		}
		return true;
	}
	bool operator()(const string& first, const string& second )
	{
		if( first[0] == '-' && second[0] != '-' )		
			return true;
		else if( first[0] != '-' && second[0] == '-' )		
			return false;
		else if( first[0] == '-' && second[0] == '-' )		
		{
			if( first.size() != second.size() )
				return first.size() > second.size();
			else
				return comp(first,second) != true;
		}
		else
		{
			if( first.size() != second.size() )
				return first.size() < second.size();
			else	
				return comp(first,second);
		}
	}
};

struct str_cmp
{
	char no_case(char c)
	{
		if( c >= 'a' && c <= 'z' )
			c = c-'a'+'A';
		return c;
	}
	bool operator()(const string& first, const string& second )
	{
		size_t len = min(first.size(),second.size());
		for( size_t i = 0; i < len; i++ )
		{
			if( no_case(first[i]) < no_case(second[i]))
				return true;
			if( no_case(first[i]) > no_case(second[i]))
				return false;
		}
		return first.size() < second.size();
	}
};
string long_line;
int main()
{
	string current;
	vector<bool> vec;
	vector<string> str_vec;
	vector<string> dig_vec;
	while( getline(cin,long_line) && long_line != "." )
	{
		for( size_t i = 0; i < long_line.size(); i++ )
		{
			if( long_line[i] == ' ' )
				continue;
			else if( long_line[i] != ',' && long_line[i] != '.' )						current.push_back(long_line[i]);
			else
			{
				if( (current[0] >= 'a' && current[0] <= 'z' )||
					(current[0] >= 'A' && current[0] <= 'Z' ))
				{
					str_vec.push_back(current);
					vec.push_back(true);
				}
				else
				{
					dig_vec.push_back(current);
					vec.push_back(false);
				}
				current.clear();
			}
		}
		sort(str_vec.begin(),str_vec.end(),str_cmp());
		sort(dig_vec.begin(),dig_vec.end(),comp_t());
		for( size_t i = 0,j = 0,k = 0; i < vec.size(); i++ )
		{
			if( i != 0 )
				cout << ", ";
			if( vec[i] == true )	
				cout << str_vec[j++];
			else
				cout << dig_vec[k++];
		}
		cout << "." << endl;
		vec.clear();
		long_line.clear();
		str_vec.clear();
		dig_vec.clear();
	}
	return 0;
}
