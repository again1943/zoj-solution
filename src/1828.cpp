#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> fibonacci;
string add_string( string& first, string& second )
{
	int carry = 0;
	int temp  = 0;
	string dest;
	string& short_str = first.size() > second.size() ? second:first;
	string& long_str = first.size() > second.size() ? first:second;
	for( size_t j = 0; j < short_str.size(); j++ )
	{
		temp = carry + (long_str[j]-'0')+(short_str[j]-'0');
		carry = temp >= 10 ? 1 : 0;
		temp = temp >= 10 ? (temp-10):temp;
		dest.push_back( temp+'0' );
	}
	for( size_t j = short_str.size(); j < long_str.size(); j++ )
	{
		temp = carry + (long_str[j]-'0');
		carry  = temp >= 10?1:0;
		temp = temp >=10?(temp-10):temp;
		dest.push_back(temp + '0');
	}
	if( carry == 1 )
		dest.push_back( carry+'0' ); 
	return dest;
}
int main()
{
	fibonacci.push_back("1");
	fibonacci.push_back("1");
	unsigned int num;
	string temp;
	while( cin >> num )
	{
		size_t size = fibonacci.size();
		if( num >= size )
		{
			for( size_t i = size; i <= num; i++ )
				fibonacci.push_back( 
				add_string( fibonacci[i-2],fibonacci[i-1] ) );
		}
		temp = fibonacci[num-1];
		reverse( temp.begin(),temp.end() );
		cout << temp << endl;
		temp.clear();
	}
	return 0;
}
