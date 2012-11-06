#include<iostream>
#include<set>
#include<algorithm>
#include<map>
#include<vector>
#include<utility>
#include<sstream>
using namespace std;

struct used {
	pair<int, int> vect;
	pair<int, int> point;
	bool operator==(const used& two)const
	{
		if (vect.first*two.vect.second != vect.second*two.vect.first)
			return false;
		pair<int,int> tmp;
		tmp.first = two.point.first - point.first;
		tmp.second = two.point.second - point.second;
		return vect.first*tmp.second == vect.second*tmp.first;
	}
};

struct sort_op
{
	bool operator()(const pair<int,int>& one, const pair<int,int>& two )
	{
		if( one.first != two.first )
			return two.first > one.first;
		else
			return two.second > one.second;
	}
};
struct comp_op
{
	bool operator()(const used& one,const used& two)
	{
		if (one.vect.first*two.vect.second < one.vect.second*two.vect.first)
			return true;
		pair<int,int> tmp;
		tmp.first = two.point.first - one.point.first;
		tmp.second = two.point.second - one.point.second;
		return one.vect.first*tmp.second < one.vect.second*tmp.first;
	}
};

struct comp_op2
{
	bool operator()(const pair<int,int> & one,const pair<int,int> & two)
	{
		return one.first*two.second < one.second*two.first;
	}
};

struct line_t
{
	int size;
	int index[15];
};

vector<pair<int,int> >points;

vector<line_t> all_lines;

map<pair<int,int>,int,comp_op2> indentify;

vector<used> used_vec;

void print(stringstream& ss, int n)
{
	int tmp = n;
	if (!tmp)
		tmp = 1;
	while (tmp < 1000) {
		ss << " ";
		tmp *= 10;
	}
	ss << n;
}

int get_all_lines(int i, stringstream& ss )
{
	used temp;
	map<pair<int,int>,int,comp_op2>::iterator pos;
	line_t tmp;

	for( int j = i+1; j < points.size(); j++ )
	{
		temp.vect = make_pair(points[j].first-points[i].first,
			points[j].second-points[i].second);
		temp.point = points[i];
		bool flag = false;
		for (int i=0; i<used_vec.size(); i++)
			if (used_vec[i] == temp) {
				flag = true;
				break;
			}
		if( !flag )
		{
			if( (pos = indentify.find( temp.vect )) == indentify.end() )
			{
				tmp.size = 2;
				tmp.index[0] = i;
				tmp.index[1] = j;

				all_lines.push_back(tmp);
				indentify.insert(make_pair(temp.vect,all_lines.size()-1));
			}
			else
			{
				int idx = pos->second;
				all_lines[idx].index[all_lines[idx].size++] = j;
			}
		}
	}

	bool flag = false;
	for( int j = 0; j < all_lines.size(); j++ )
	{
		if( all_lines[j].size > 2 )
		{
			if( all_lines[j].size > 3 )
			{
				int x = all_lines[j].index[0];
				int y = all_lines[j].index[1];
				used buf;
				buf.vect = make_pair(points[x].first-points[y].first,
					points[x].second-points[y].second);
				buf.point = make_pair(points[x].first, points[x].second);
				used_vec.push_back(buf);
			}
			for( int k = 0; k < all_lines[j].size; k++ )
			{
				ss << "(";
				print(ss, points[all_lines[j].index[k]].first);
				ss << ","; 
				print(ss, points[all_lines[j].index[k]].second);
				ss << ")"; 
			}
			ss << endl;
			flag = true;
		}
	}
	all_lines.clear();
	indentify.clear();
	if (flag)
		return 1;
	else
		return 0;
}
/*
void printlines()
{
stringstream ss;
int flag = 0;
for( int j = 0; j < all_lines.size(); j++ )
{
if( all_lines[j].size > 2 )
{
if( all_lines[j].size > 3 )
{
int x = all_lines[j].index[0];
int y = all_lines[j].index[1];
used_vec.insert(make_pair(points[x].first-points[y].first,
points[x].second-points[y].second));
}
for( int k = 0; k < all_lines[j].size; k++ )
{
ss << "( " << points[all_lines[j].index[k]].first << 
", " << 
points[all_lines[j].index[k]].second << ")"; 
}
ss << endl;
flag++;
}
}
if (flag >= 1 )
{
if( flag == 1 )
cout << "The following lines were found:\n"; 
cout << ss.str();
}
else
cout << "No lines were found";
all_lines.clear();
indentify.clear();

}
*/
int main()
{
	int x,y;
	//freopen("in.txt", "r", stdin);
	cin >> x >> y;

	while ( x > 0 || y > 0)
	{
		points.push_back(make_pair(x,y));
		cin >> x >> y;
		while( x > 0 || y > 0 )
		{
			points.push_back(make_pair(x,y));
			cin >> x >> y;
		}
		stable_sort(points.begin(),points.end(),sort_op());
#ifdef DEBUG
		for( int i = 0; i < points.size(); i++ )
			cout << "(" << points[i].first << ","
			<< points[i].second << ")";
		cout << endl;
#endif
		stringstream ss;
		int flag = 0;
		for( int i = 0; i < points.size()-2; i++ )
			flag += get_all_lines(i, ss);
		if (flag)
		{
			cout << "The following lines were found:\n"; 
			cout << ss.str();
		}
		else
			cout << "No lines were found\n";

		points.clear();
		used_vec.clear();
		cin >> x >> y;
	}
}
