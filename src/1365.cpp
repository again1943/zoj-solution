#include<iostream>
using namespace std;

class zoj1365_t
{
	private:
		string city;
		int miles;
		int earn;
		char code;
	public:
		zoj1365_t()
		{
			earn = 0;
		}
		void reset()
		{
			city.clear();
			earn = 0;
		}
		int read()
		{
			cin >> city;	
			if( city == "#" )
				return -1;
			else if( city == "0")
				return 0;
			else
			{
				city.clear();
				cin >> city >> miles >> code;
				return 1;
			}

		}
		
		void process()
		{
			switch( code )	
			{
				case 'F':
					earn += 2*miles;
					break;
				case 'B':
					earn += miles + (miles+1)/2;
					break;
				case 'Y':
					earn += miles <= 500 ? 500:miles;
					break;
				default:
					break;
			}
		}
		void print()
		{
			cout << earn << endl;
		}
		 
};
int main()
{
	int tag;
	zoj1365_t zoj1365;
	tag = zoj1365.read();
	while(  tag >= 0 )
	{
		if( tag > 0 )	
			zoj1365.process();
		else
		{
			zoj1365.print();
			zoj1365.reset();
		}
		tag = zoj1365.read();

	}
	return 0;
}
