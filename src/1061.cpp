#include<string>
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<string>backward;
vector<string>forward;

int main()
{
	int test_case;
	string temp;
	string current_url;
	cin >> test_case;
	for( int k = 0; k < test_case; k++ )
	{
		//backward.push_back("http://www.acm.org/");
		if(k >= 1)
			cout << endl;
		current_url = "http://www.acm.org/";
		cin >> temp;
		while( temp != "QUIT" )
		{
			if(temp == "VISIT")
			{
				backward.push_back(current_url);
				cin >> current_url;
				forward.clear();
				cout << current_url << endl;
			}
			else if(temp == "BACK")
			{
				if(backward.empty() == true )
					cout << "Ignored" << endl;
				else
				{
					forward.push_back(current_url);
					current_url = backward.back();
					backward.pop_back();
					cout << current_url << endl;
				}
			}
			else
			{
				if (forward.empty() == true )
					cout << "Ignored" << endl;
				else
				{
					backward.push_back(current_url);
					current_url = forward.back();
					forward.pop_back();
					cout << current_url << endl;;
				}
			}
			cin >> temp;
		}
		backward.clear();
		forward.clear();
		current_url.clear();
	}
	return 0;
}