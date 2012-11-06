#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	string source,target;
	string::iterator pos;

	while( cin >> source >> target )
	{
		pos = target.begin();
		for( int i = 0; 
				i < static_cast<int>(source.size()); i++ )	
		{
			if( (pos = find(pos,target.end(),source[i]))
					!= target.end())	
				++pos;
			else
			{
				cout << "No" << endl;
				goto here;
			}
		}

		cout << "Yes" << endl;
	here:
		source.clear();
		target.clear();
	}

	return 0;
}
