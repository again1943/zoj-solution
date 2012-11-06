#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
void deal_with_line( string& line )
{
	string::iterator start = line.begin();
	string::iterator end = line.begin();
	while( end != line.end() )
	{
		++end;
		if( *end == ' ' )
		{
			reverse( start,end );
			start = end + 1;
			end = start;
		}

	}

	reverse( start,end);
}
int main()
{
	int N;
	int L;
	string line;
	cin >> N;
	getline( cin,line );
	for( int i = 0; i < N-1; i++ )
	{
		getline( cin, line );
		cin >> L;
		getline( cin,line );
		line.clear();
		for( int j = 0; j < L; j++ )
		{	
			getline( cin,line );
			deal_with_line( line );
			cout << line << endl;
			line.clear();
		}
		cout << endl;
	}
	
	getline( cin, line );
	cin >> L;
	getline( cin,line );
	line.clear();
	for( int j = 0; j < L; j++ )
	{	
		getline( cin,line );
		deal_with_line( line );
		cout << line << endl;
		line.clear();
	}


	return 0;
}
