#include<set>
#include<cstdio>
#include<queue>
#include<utility>
#include<list>
#define MAX_VILLAGE 27
using namespace std;


typedef pair< pair<int,int>, int > triple;

class sort_op
{
public:
	bool operator()( triple one, triple two)
	{
		return one.second > two.second;
	}
};

set<int> already;

list< pair<int,int> > graph[MAX_VILLAGE];

priority_queue< triple, vector<triple>,sort_op> edge;

void init()
{
	already.clear();
	for( int i = 0; i < MAX_VILLAGE; i++ )
		graph[i].clear();
}
void push_all( int point )
{
	for( list<pair<int,int> >::iterator pos = graph[point].begin();
			pos != graph[point].end();++pos )
	{
		if( already.find( point ) == already.end() ||
				already.find( pos->first ) == already.end() )
		{
			pair<int,int> temp;
			temp.first = ( point < pos->first )?point:pos->first;
			temp.second = ( point > pos->first )?point:pos->first;
			edge.push( make_pair(temp,pos->second ));
		}
	}
}
int main()
{
	char point;
	int num;
	int adj_point;
	int distance;
	scanf("%d",&num);
	getchar();
	while( num != 0 )
	{
		init();
		distance = 0;
		for( int i = 0; i < num-1; i++ )
		{
			scanf("%c%d",&point,&adj_point);
			getchar();
			for( int j = 0; j < adj_point; j++ )
			{
				char c;
				int dist;
				scanf("%c%d",&c,&dist);
				getchar();
				graph[point-'A'].push_back(make_pair(c-'A',dist));
				graph[c-'A'].push_back( make_pair( point-'A',dist));
			}	
		}
		push_all(0);
		already.insert(0);
		while( edge.empty() != true )
		{
			triple temp = edge.top();
			edge.pop();
			set<int>::iterator after = already.find( temp.first.second );
			set<int>::iterator before = already.find( temp.first.first );
			set<int>::iterator end = already.end();
			if( after == end )
			{
				distance += temp.second;
				already.insert( temp.first.second );
			}
			else if( before == end )
			{
				distance += temp.second;
				already.insert( temp.first.first );
			}
			push_all( temp.first.second );
			push_all( temp.first.first );
		}
		printf("%d\n",distance);
		scanf("%d",&num);
		getchar();
			
	}
}
