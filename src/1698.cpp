/*
 * =====================================================================================
 *
 *       Filename:  acm1698.cpp
 *
 *    Description:  solution to zoj 1698
 *
 *        Version:  1.0
 *        Created:  2007年03月11日 00时44分24秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars
 *        Company:  Mars
 *
 * =====================================================================================
 */


#include<string>
#include<iostream>

using namespace std;

bool inline is_vowel(char c)
{
	return (c == 'a' ||
		c == 'e' ||
		c == 'i' ||
		c == 'o' ||
		c == 'u'
		);
}


bool check_vowel( string& passwd )
{
	for( size_t i = 0; i < passwd.size(); i++ )
		if( is_vowel(passwd[i]) == true )
			return true;
	return false;
}

bool check_consecutive( string& passwd)
{
	int count = 0;	
	bool state;

	state = is_vowel(passwd[0]);
	count = 1;

	for( size_t i = 1; i < passwd.size(); i++ )
	{
		if( state == is_vowel(passwd[i]))	
		{
			count++;
			if( count == 3 )
				return false;
		}
		else
		{
			state = is_vowel(passwd[i]);
			count = 1;
		}
	}

	return true;
}

bool check_same(string& passwd)
{
	for( size_t i = 0; i < passwd.size()-1;i++ )	
	{
		if( passwd[i] == passwd[i+1]) 
		{
			if( passwd[i] != 'o' && passwd[i] != 'e')
				return false;
		}

	}

	return true;
}

inline bool check( string& passwd)
{
	return check_vowel(passwd)&&check_consecutive(passwd)&&check_same(passwd);	
}
int main()
{
	string passwd;	
	cin >> passwd;

	while( passwd != "end")
	{
		cout << "<" << passwd << "> is " <<
			(check(passwd) == true ? "":"not ")
			<< "acceptable." << endl;			
		passwd.clear();
		cin >> passwd;
	}

	return 0;
}

