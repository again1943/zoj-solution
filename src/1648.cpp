#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>

#define eps 1e-8

using namespace std;

struct point_t
{
	double x;
	double y;
};

struct line_t
{
	point_t l;
	point_t r;
};

struct sort_op
{
	bool operator()(const line_t& first, const line_t& second )
	{
		return first.l.x > second.l.x;
	}
};

//here point_t is used as vector
inline double cross_product(point_t& first,point_t& second)
{
	return first.x*second.y-first.y*second.x;
}

inline int sign(double x)
{
	return x >= 0 ? 1:-1;
}

bool check_line_cross( line_t& first, line_t& second )
{
	point_t one;
	point_t two;
	point_t mid;

	if( max(second.l.y,second.r.y) < min( first.l.y,first.r.y)||
			min(second.l.y,second.r.y)>max( first.l.y,first.r.y))
		return true;
	else
	{
		one.x = second.l.x-first.l.x;
		one.y = second.l.y-first.l.y;
		two.x = second.r.x-first.l.x;
		two.y = second.r.y-first.l.y;
		mid.x = first.r.x-first.l.x;
		mid.y = first.r.y-first.l.y;
		if( sign( cross_product(mid,one))*sign( cross_product(mid,two)) > 0)
			return true;
		else
			return false;

	}
}
bool check_cross( vector<line_t>& lines )
{
	//sort the lines by leftmost point's x coordinate
	int i,j;
	int size = lines.size();
	stable_sort(lines.begin(),lines.end(),sort_op());	

	i = 0;	
	while( i < size )
	{
		j = i+1;	
		while( j < size && lines[j].l.x < lines[i].r.x )
		{
			if( check_line_cross(lines[i],lines[j]) == false )	
				return false;	
			else
				j++;
		}
		i++;
	}
	return true;
}


int main()
{
	int n;
	line_t single;
	vector<line_t>lines;
	while( cin >> n )
	{
		for( int i = 0; i < n; i++ )
		{
			cin >> single.l.x >> single.l.y >> single.r.x >> single.r.y;
			if( single.l.x > single.r.x )
				swap(single.l,single.r);
			lines.push_back(single);
		}
		if( check_cross(lines) == false )
			cout << "burned!" << endl;
		else
			cout <<"ok!"<< endl;
		lines.clear();
	}
	return 0;

}
