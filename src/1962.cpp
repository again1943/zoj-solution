#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

vector<string> fibonacci(600);


void big_integer_add( string& first,string& second,string& dest)
{
	string temp;
	
	int carry,c;
	int x = first.size()-1;
	int y = second.size()-1;

	if( x >= y )
	{
		carry = 0;
		while( y >= 0 )
		{
			c = (first[x--]-'0')+(second[y--]-'0')+carry;
			carry = c / 10;
			c = c%10;
			temp.push_back(c+'0');
		}
		while( x >= 0 )
		{
			c = first[x--]-'0'+carry;
			carry = c/10;
			c = c%10;
			temp.push_back(c+'0');
		}
		if( carry != 0 )
			temp.push_back(carry+'0');
		
	}
	else
	{
		carry = 0;
		while( x >= 0 )
		{
			c = (first[x--]-'0')+(second[y--]-'0')+carry;
			carry = c / 10;
			c = c%10;
			temp.push_back(c+'0');
		}
		while( y >= 0 )
		{
			c = second[y--]-'0'+carry;
			carry = c/10;
			c = c%10;
			temp.push_back(c+'0');
		}
		if( carry != 0 )
			temp.push_back(carry+'0');
		
	}

	reverse(temp.begin(),temp.end());
	dest = temp;
}
void set_fib()
{
	int n = 3;
	fibonacci[1] = "1";	
	fibonacci[2] = "2";
	
	do
	{
		big_integer_add(fibonacci[n-2],fibonacci[n-1],fibonacci[n]);
		n++;
	}while( fibonacci[n-1].size() <= 100 );
};

int comp_op(const string& first, const string& second )
{
	if( first.size() > second.size())
		return 1;
	else if( first.size() < second.size() )
		return -1;
	else
		return first.compare(second);
}

int find_pos( const vector<string>& vs, const string& source, bool& status)
{
	int state_one;
	int state_two;


	if( source < vs[1] )
	{
		status = false;
		return 0;
	}

	state_one = comp_op(source,vs[1]);

	for( int i = 1; i < static_cast<int>(vs.size()-1); i++ )
	{
		state_two = comp_op(source,vs[i+1]);

		if( state_one == 0 )
		{
			status = true;
			return i;
		}
		
		if( state_one > 0 && state_two < 0 )
		{
			status = false;
			return i;
		}

		state_one = state_two;
	}

	return -1;
}


int main()
{
	string first, second;
	int one,two;
	bool state[2];

	set_fib();
	cin >> first >> second;


	while( first != "0" || second != "0")
	{
		one = find_pos(fibonacci,first,state[0]);			
		two = find_pos(fibonacci,second,state[1]);
		cout << (state[0] == true? two-one+1:two-one) << endl;

		first.clear();
		second.clear();

		cin >> first >> second;

	}
	
	return 0;
}
