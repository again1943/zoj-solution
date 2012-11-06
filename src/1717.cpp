
#include<iostream>
#include<algorithm>
#include<utility>

#define SIZE 	70
#define LEFT 	0
#define UP	1

using namespace std;
struct room_t
{
	char elem;
	int count;
	int prev;
};

class zoj1717_t
{
	private:
		int w;
		int h;
		room_t room[SIZE+1][SIZE+1];

		void set()
		{
			for( int i = 0; i <= SIZE+1; i++ )
				room[i][0].count = room[0][i].count = 0;
		}
		void perform_elem( int x, int y );
		int compare( int x,int y, int a,int b, int depth );

	public:
		pair<int,int>best;
		bool read();
		void perform()
		{
			for( int i = 1; i <= h; i++ )
				for( int j = 1; j <= w; j++ )
					perform_elem(i,j);
		}

		pair<int,int> find_best();
		void print(int x, int y );

};
bool zoj1717_t::read()
{
	cin >> w >> h;
	if( w != 0 )
	{
		for( int i = 1; i <= h; i++ )	
		for( int j = 1; j <= w; j++ )
			cin >> room[i][j].elem;
		set();
		return true;
	}
	else
		return false;
}
int zoj1717_t::compare( int x, int y, int a, int b, int depth)
{
	if( depth == 1)
	{
	 	if(room[x][y].elem == room[a][b].elem)	
			return 0;		
		else
			return room[x][y].elem > room[a][b].elem ? 1:-1;
	}
	else
	{
		bool first = (room[x][y].prev == UP);
		bool second = (room[a][b].prev == UP );
		int temp = compare(
				(first == true)?x-1:x,
				(first == true)?y:y-1,
				(second == true )?a-1:a,
				(second == true )?b:b-1,
				depth-1);
		if( temp != 0 )
			return temp;
		else
		{
			if(room[x][y].elem == room[a][b].elem)	
				return 0;		
			else
				return room[x][y].elem > room[a][b].elem ? 1:-1;
		}
	}
}

void zoj1717_t::perform_elem(int x, int y)
{
	if( room[x][y].elem < '0' || room[x][y].elem > '9' )
	{
		room[x][y].count = 0;
		room[x][y].prev = -1;
	}
	else
	{
		if( room[x-1][y].count == 0 && room[x][y-1].count == 0 )
		{
			room[x][y].prev = -1;
			room[x][y].count = (room[x][y].elem != '0' ) ? 1:0;
		}
		else
		{
			if( room[x-1][y].count > room[x][y-1].count )
			{
				room[x][y].prev = UP;
				room[x][y].count = room[x-1][y].count + 1;
			}
			else if( room[x-1][y].count < room[x][y-1].count)
			{
				room[x][y].prev = LEFT;
				room[x][y].count = room[x][y-1].count + 1;
			}
			else // room[x][y-1].count == room[x-1][y] and  both are not zero;
			{
				if( compare(x-1,y,x,y-1,room[x][y-1].count ) >= 0 )	
				{
					room[x][y].prev = UP;
					room[x][y].count = room[x-1][y].count + 1;
				}
				else
				{
					room[x][y].prev = LEFT;
					room[x][y].count = room[x][y-1].count + 1;
				}
			}
		}
	}
}
pair<int,int> zoj1717_t::find_best()
{
	int x,y;	
	int len = 0;
	for( int i = 1; i <= h; i++ )
	for( int j = 1; j <= w; j++ )
	{
		if( len < room[i][j].count )
		{
			len = room[i][j].count;
			x = i;
			y = j;
		}
		else
		{
			if( len != 0 && room[i][j].count == len )
			{
				int temp = compare(x,y,i,j,len);
				if( temp < 0 )
				{
					x = i;
					y = j;
				}
			}
		}
	}
	return make_pair(x,y);
}
void zoj1717_t::print(int x, int y )
{
	int depth = room[x][y].count;
	if( depth == 1 )
		cout << room[x][y].elem;
	else
	{
		print(
			(room[x][y].prev == UP) ? x-1:x,
			 (room[x][y].prev == UP) ? y:y-1
			);
		cout << room[x][y].elem;
	}
}


int main()
{
	zoj1717_t zoj1717;

	while( zoj1717.read())
	{
		zoj1717.perform();	
		zoj1717.best = zoj1717.find_best();
		zoj1717.print( zoj1717.best.first, zoj1717.best.second);
		cout << endl;
	}
	return 0;
}
