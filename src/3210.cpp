#include <stack>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

bool verify_queue(vector<int>& in, vector<int>& out)
{
	size_t i,s;
	if( in.size() != out.size() )
		return false;
	s = in.size();
	for( i = 0; i < s; i++ )
		if( in[i] != out[i] )
			return false;
	return true;
}
bool verify_stack(vector<int>& in, vector<int>& out)
{
	size_t i,j,s;
	if( in.size() != out.size() )
		return false;
	s = in.size();
	for( i = 0,j = s-1; i < s; i++,j-- )
		if( in[i] != out[j] )
			return false;
	return true;
}
int main()
{
	int n,i,e,t,m;
	bool istack,iqueue;
	vector<int> in,out;
	cin >> n;
	for( t = 0; t < n; t++ )
	{
		cin >> m;
		for( i = 0; i < m; i++ )
		{
			cin >> e;
			in.push_back(e);
		}
		for( i = 0; i < m; i++ )
		{
			cin >> e;
			out.push_back(e);
		}
		istack = verify_stack(in,out);
		iqueue = verify_queue(in,out);
		if( istack == true && iqueue == true )
			cout << "both" << endl;
		else if( istack == true )
			cout << "stack" << endl;
		else if( iqueue == true )
			cout << "queue" << endl;
		else
			cout << "neither" << endl;
		in.clear();
		out.clear();
	}
	return 0;
}