#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{

	vector<string>code;
	string line;
	int num = 1;
	while( cin >> line )
	{
		if( line != "9" )
		{
			code.push_back(line);
			line.clear();
		}
		else
		{
			stable_sort( code.begin(), code.end() );
			bool flag = true;
			for( int i = 0; i < code.size(); i++ )
			for( int j = i+1; j < code.size(); j++ )
			{
				if( code[i] == code[j].substr( 0,code[i].size() ))
				{	
					flag = false;
					break;
				}
			}

			if( flag == true )
				cout << "Set " << num++ 
						<<" is immediately decodable"<<endl; 
			else
				cout << "Set " << num++ 
						<<" is not immediately decodable"<<endl; 
			code.clear();
		}

	}
	return 0;
}
