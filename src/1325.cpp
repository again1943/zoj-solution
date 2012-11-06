#include<string>
#include<iostream> 
#include<algorithm> 
using namespace std;

char map[] = {'A','\0','\0','\0','3','\0','\0','H','I','L','\0','J',
		'M','\0','O','\0','\0','\0','2','T','U','V','W','X',
		'Y','5','1','S','E','\0','Z','\0','\0','8','\0'};
bool is_palindrome(const string& line )
{
	int i,n;
	for( i = 0,n = line.size()-1; i < n; i++,n-- )
	{
		if( line[i] != line[n] )	
			return false;
	}
	return true;
}

inline char get_code(char c)
{
	if( c >= '1' && c <= '9' ) 
		return map[c-'1'+26];
	else
	 	return map[c-'A'];
}
bool is_mirror(const string& line )
{
	int i,n;	
	for( i = 0, n = line.size()-1; i <= n ; i++,n-- )
	{
		if( get_code(line[i]) != line[n] || get_code(line[n]) != line[i] )
			return false;
	}
	return true;
}

int main()
{
	string line;
	bool mirror;
	bool palindrome;
	while( cin >> line )
	{
		palindrome = is_palindrome(line);
		mirror = is_mirror(line);
		if( palindrome == false && mirror == false )
			cout << line << " -- is not a palindrome.\n" << std::endl; 
		else if( palindrome == true && mirror == false )
			cout << line << " -- is a regular palindrome.\n" << std::endl;
		else if( palindrome == false && mirror == true )
			cout << line << " -- is a mirrored string.\n" << std::endl;
		else
			cout << line << " -- is a mirrored palindrome.\n" << std::endl;
	}
	return 0;

}
