#include<cstdio>
#include<deque>
using namespace std;

#define RAN_NORMAL 0
#define RAN_OFF -1
#define RAN_INTO -2

struct pos_t
{
	int x,y;
	pos_t()
	{
		x = y = 0;
	}
	pos_t( int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

inline bool inside( pos_t& t )
{
	return (t.x >= 1 && t.x <= 50 && t.y >= 1 && t.y <= 50);
}

void advance_tail( deque<pos_t>& vec )
{
	int n = vec.size()-1;
	if( vec[n].x == vec[n-1].x )
		vec[n].y += ( vec[n].y > vec[n-1].y ) ? -1:1;
	else
		vec[n].x += ( vec[n].x > vec[n-1].x ) ? -1:1;
	if( vec[n].x == vec[n-1].x && vec[n].y == vec[n-1].y )
		vec.pop_back();
}
int check_into( deque<pos_t>& vec )
{
	pos_t head = vec[0];
	for( size_t i = 2; i < vec.size(); i++ )		
	{
		if( vec[i].x == vec[i-1].x && vec[i].x == head.x &&
			head.y >= min(vec[i].y,vec[i-1].y) && 
			head.y <= max(vec[i].y,vec[i-1].y) )
			return -1;
		if( vec[i].y == vec[i-1].y && vec[i].y == head.y &&
			head.x >= min(vec[i].x,vec[i-1].x) && 
			head.x <= max(vec[i].x,vec[i-1].x) )
			return -1;
	}
	return 1;

}

int check_west( deque<pos_t>& vec )
{
	pos_t head;

	if( vec[0].x == vec[1].x && vec[0].y > vec[1].y )
		return RAN_INTO;
	else if( vec[0].x == vec[1].x && vec[0].y < vec[1].y )
		vec[0].y--;		
	else
	{
		head.x = vec[0].x;	
		head.y = vec[0].y-1;
		vec.push_front(head);
	}

	if( inside(vec[0]) == false )
		return RAN_OFF;
	advance_tail(vec);
	if( check_into(vec) < 0 )	
		return RAN_INTO;
	return RAN_NORMAL;
}

int check_east( deque<pos_t>& vec )
{
	pos_t head;

	if( vec[0].x == vec[1].x && vec[0].y < vec[1].y )
		return RAN_INTO;
	else if( vec[0].x == vec[1].x && vec[0].y > vec[1].y )
		vec[0].y++;		
	else
	{
		head.x = vec[0].x;	
		head.y = vec[0].y+1;
		vec.push_front(head);
	}

	if( inside(vec[0]) == false )
		return RAN_OFF;
	advance_tail(vec);
	if( check_into(vec) < 0 )	
		return RAN_INTO;
	return RAN_NORMAL;
}

int check_north(deque<pos_t>& vec )
{
	pos_t head;

	if( vec[0].y == vec[1].y && vec[0].x > vec[1].x )
		return RAN_INTO;
	else if( vec[0].y == vec[1].y && vec[0].x < vec[1].x )
		vec[0].x--;		
	else
	{
		head.y = vec[0].y;	
		head.x = vec[0].x-1;
		vec.push_front(head);
	}

	if( inside(vec[0]) == false )
		return RAN_OFF;
	advance_tail(vec);
	if( check_into(vec) < 0 )	
		return RAN_INTO;
	return RAN_NORMAL;

}

int check_south(deque<pos_t>& vec )
{
	pos_t head;

	if( vec[0].y == vec[1].y && vec[0].x < vec[1].x )
		return RAN_INTO;
	else if( vec[0].y == vec[1].y && vec[0].x > vec[1].x )
		vec[0].x++;		
	else
	{
		head.y = vec[0].y;	
		head.x = vec[0].x+1;
		vec.push_front(head);
	}

	if( inside(vec[0]) == false )
		return RAN_OFF;
	advance_tail(vec);
	if( check_into(vec) < 0 )	
		return RAN_INTO;
	return RAN_NORMAL;
}

int main()
{
	int ret,n,i;
	char step[128];
	deque<pos_t> vec;
	while( scanf("%d",&n) && n != 0 )
	{
		scanf("%s",step);
		vec.push_front(pos_t(25,30));
		vec.push_back(pos_t(25,11));

		for(i = 1,ret = RAN_NORMAL; i <= n ; i++ )
		{
			switch( step[i-1] )
			{
				case 'W':
					ret = check_west(vec);
					break;
				case 'E':
					ret = check_east(vec);
					break;
				case 'S':
					ret = check_south(vec);
					break;
				case 'N':
					ret = check_north(vec);
					break;
				default:
					break;
			}
			if( ret < 0 )	
				break;
		}
		if( ret == RAN_NORMAL )
			printf("The worm successfully made all %d moves.\n",n);
		else if( ret == RAN_OFF )
			printf("The worm ran off the board on move %d.\n",i);
		else
			printf("The worm ran into itself on move %d.\n",i);
		vec.clear();
	}
	return 0;
}
