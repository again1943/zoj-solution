#include<map>
#include<string>
#include<iostream>
using namespace std;

void pre_do( map<string,int>& M )
{
	int a,b,c,d,e,C;
	string S;	
	for(  a = C = 0; a < 26; a++ )
	{
		S += a+'a';
		M.insert(make_pair(S,++C));
		S.clear();
	}
	for( a = 0; a < 26; a++ )
	for( b = a+1; b < 26; b++ )
	{
		S += a+'a';
		S += b+'a';
		M.insert(make_pair(S,++C));
		S.clear();
	}
	for( a = 0; a < 26; a++ )
	for( b = a+1; b < 26; b++ )
	for( c = b+1; c < 26; c++ )
	{
		S += a+'a';
		S += b+'a';
		S += c+'a';
		M.insert(make_pair(S,++C));
		S.clear();
	}

	for( a = 0; a < 26; a++ )
	for( b = a+1; b < 26; b++ )
	for( c = b+1; c < 26; c++ )
	for( d = c+1; d < 26; d++ )
	{
		S += a+'a';
		S += b+'a';
		S += c+'a';
		S += d+'a';
		M.insert(make_pair(S,++C));
		S.clear();
	}
	for( a = 0; a < 26; a++ )
	for( b = a+1; b < 26; b++ )
	for( c = b+1; c < 26; c++ )
	for( d = c+1; d < 26; d++ )
	for( e = d+1; e < 26; e++ )
	{
		S += a+'a';
		S += b+'a';
		S += c+'a';
		S += d+'a';
		S += e+'a';
		M.insert(make_pair(S,++C));
		S.clear();
	}
}

int main()
{
	string S;
	map<string,int>M;

	pre_do(M);
	while( cin >> S )
		cout << M[S]<< endl;
	return 0;
}
