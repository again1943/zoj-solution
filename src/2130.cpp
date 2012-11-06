#include<iostream>
#include<algorithm>
#include<utility>

#define SIZE 60
using namespace std;

struct rectangular
{
	int h,w;
	char data[SIZE][SIZE+1];
};

class zoj2130_t
{
	private:
		rectangular picture;
		rectangular spot;
		int count;
		bool match( rectangular& x,rectangular& y, int start_x, int start_y);
	public:
		bool read();
		void deal();
		void print()
		{
			cout << count << endl;
		}
};

bool zoj2130_t::read()
{
	if( cin >> picture.h >> picture.w >> spot.h >> spot.w )	
	{
		for( int i = 0; i < picture.h; i++ )
			cin >> picture.data[i];
		for( int i = 0; i < spot.h; i++ )
			cin >> spot.data[i];
		return true;
	}
	else
		return false;
}

bool zoj2130_t::match( rectangular& x, rectangular& y, int start_x, int start_y )
{
	for( int i = 0; i < x.h; i++ )
	for( int j = 0; j < x.w; j++ )
	{
		if( x.data[i][j] != '.' && x.data[i][j] != y.data[start_x+i][start_y+j] )
			return false;
	}
	return true;
}

void zoj2130_t::deal()
{
	count = 0;
	for( int i = 0; i+spot.h <= picture.h; i++ )
		for( int j = 0; j+spot.w <= picture.w; j++ )
			if( match( spot,picture,i,j) == true )
				count++;
}

int main()
{
	zoj2130_t zoj2130;
	while( zoj2130.read())
	{
		zoj2130.deal();
		zoj2130.print();
	}
	return 0;
}
