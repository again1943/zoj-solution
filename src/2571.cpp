#include<string>
#include<iostream>
using namespace std;

int get_num(const string& src, size_t& pos )
{
	int rep = 0;
	while( src[pos] >= '0' && src[pos] <= '9' )
		rep = rep*10+src[pos++]-'0';
	return rep;
}
string do_work( const string& src,size_t& pos )
{
	int i;
	int rep = 1;
	string ret,tmp;
	while( pos < src.size() )	
	{
		if( src[pos] >= '0' && src[pos] <= '9' )	
		{
			rep = get_num(src,pos);					
			if( src[pos] >= 'a' && src[pos] <= 'z' )
				tmp = string(1,src[pos++]);
			else
				tmp = do_work(src,++pos);
			for( i = 0; i < rep; i++ )
				ret += tmp;
			rep = 1;
		}
		if( src[pos] >= 'a' && src[pos] <= 'z' )	
			ret.push_back(src[pos++]);
		if( src[pos] == ')' )
		{
			pos += 1;
			return ret;
		}
	}
	return ret;
}
int main()
{
	int i,n;
	size_t pos;
	string src;
	cin >> n;
	for( i = 0; i < n; i++ )
	{
		pos = 0;
		cin >> src;
		cout << do_work(src,pos) << endl;
	}
	return 0;
}
