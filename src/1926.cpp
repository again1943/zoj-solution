#include<string>
#include<iostream>
using namespace std;

int main()
{
	int high = 11;
	int low  = 0;
	int guess;
	string response;
	cin >> guess;
	getchar();
	response.clear();
	while( guess !=  0 )
	{
		high = 10;
		low = 1;
		getline(cin,response);
		while( response != "right on" )
		{
			if( response == "too high" )
				high = (high < guess-1)?high:guess-1;
			if( response == "too low" )
				low = ( low > guess+1 )?low:guess+1;
			cin >> guess;
			getchar();
			response.clear();
			getline( cin, response ); 
		}
		if( guess >= low && guess <= high )
			cout << "Stan may be honest" << endl;
		else
			cout << "Stan is dishonest" << endl;
		cin >> guess;
		getchar();
		response.clear();
	}
	return 0;
}
