#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
#define COM_LEN 12
char command[COM_LEN];

struct die_t
{
	int top,buttom;	
	int west,east;
	int north,south;
};

int main()
{
	int n,i,temp;
	die_t die;
	while( scanf("%d",&n) && n != 0 )
	{
		die.top = 1;	
		die.buttom = 6;
		die.west = 3;
		die.east = 4;
		die.north = 2;
		die.south = 5;
		for( i = 0; i < n; i++ )
		{
			scanf("%s",command);
			if( strcmp(command,"north") == 0 )
			{
				temp = die.buttom;		
				die.buttom = die.north;
				die.north = die.top;
				die.top = die.south;
				die.south = temp;
			}
			else if( strcmp( command,"south") == 0 )
			{
				temp = die.buttom;	
				die.buttom = die.south;
				die.south = die.top;
				die.top = die.north;
				die.north = temp;
			}
			else if( strcmp( command,"west") == 0 )
			{
				temp = die.buttom;	
				die.buttom = die.west;
				die.west = die.top;
				die.top = die.east;
				die.east = temp;
			}
			else
			{
				temp = die.buttom;	
				die.buttom = die.east;
				die.east = die.top;
				die.top = die.west;
				die.west = temp;
			}
		}
		printf("%d\n",die.top);
	}
	return 0;
}
