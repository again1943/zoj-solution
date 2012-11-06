#include <cstdio>
#include <cstdlib>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
#define MAX_LINE 3004
char first[MAX_LINE];
char second[MAX_LINE];
char table[MAX_LINE];

#define INF 0xfffffff

struct sort_t
{
	char* code;
	sort_t(char* c):code(c){}
	bool operator()(const pair<int,int>& a, const pair<int,int>& b)
	{
		int x,y;
		for( x = a.first,y = b.first; x <= a.second && y <= b.second; x++,y++)
			if(code[x] != code[y])
				return code[x]>code[y];
		//if( x > a.second )
		return x <= a.second;
	}
};

void minimal(char* code, int start, int end)
{
	char* p;
	int i,s,sum,size;
	vector<pair<int,int> >record;
	for( i = s = start,sum = INF; i <= end; i++ )
	{
		if( sum == INF )
			sum = ((code[i]=='0')?-1:1);
		else
			sum += ((code[i]=='0')?-1:1);

		if( sum == 0 )
		{
			record.push_back(make_pair(s,i));
			if( s+1 < i-1 )
				minimal(code,s+1,i-1);
			s = i+1;
			sum = INF;
		}
	}
	//now all the subtree are handled;
	if( record.size() <= 1)
		return;
	s = record[0].first;
	sort(record.begin(),record.end(),sort_t(code));
	for( i = 0,p = table; i < record.size(); i++ )
	{
		size = record[i].second-record[i].first+1;
		memcpy(p,code+record[i].first,size);
		p += size;
	}
	//memcpy(code,table);
	memcpy(code+s,table,p-table);
}
bool same(char* first,char* second)
{
	int x = strlen(first);
	int y = strlen(second);
	if( x != y )
		return false;
	minimal(first,0,x-1);
	minimal(second,0,y-1);
	return (strcmp(first,second)==0);
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%s%s",first,second);
		printf("%s\n",(same(first,second)?"same":"different"));
	}
	return 0;
}