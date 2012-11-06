#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
struct kill_t
{
	int time;
	string killer;
	string victim;
	kill_t(int t, const string& k, const string& v):time(t),killer(k),victim(v){}
};

struct sort_t
{
	bool operator()(const kill_t& x, const kill_t& y)
	{
		return x.time < y.time;
	}
};
vector<kill_t> kill;
map<string,int>blood;
map<string,pair<int,int> >bcount;

const char format[][64] = 
{
	"",
	"",
	"",
"%s has a Killing Spree!\n",
"%s is Dominating!\n" ,
"%s has a Mega Kill!\n",
"%s is Unstoppable!\n",
"%s is Wicked Sick!\n",
"%s has a Monster Kill!!!\n",
"%s is Godlike!\n",
"%s is Beyond Godlike! Somebody kill him!!\n" 
};
const char tripkill[][64] = 
{
	"",
	"",
	"%s just got a Double Kill!\n",
	"%s just got a Triple Kill!\n"
};
int main()
{
	int m,s,n,t,i,k;
	char line[512];
	char x[128];
	char y[128];
	map<string,int>::iterator item;
	map<string,pair<int,int> >::iterator iter;
	scanf("%d",&n);
	gets(line);
	for( i = 0; i < n; i++ )
	{
		while( gets(line) && strcmp(line,"#") != 0 )
		{
			sscanf(line,"%d:%d%s kills %s",&m,&s,x,y);
			kill.push_back(kill_t(m*60+s,x,y));
		}
		sort(kill.begin(),kill.end(),sort_t());
		printf("%s just drew First Blood!\n",kill[0].killer.c_str());
		blood.insert(make_pair(kill[0].killer,1));
		blood.insert(make_pair(kill[0].victim,0));
		bcount.insert(make_pair(kill[0].killer,make_pair(kill[0].time,1)));
		for( t = 1; t < kill.size(); t++ )
		{
			if( (item = blood.find(kill[t].killer)) != blood.end() )
			{
				item->second += 1;
				if( item->second >= 3 )
					printf(format[item->second>10?10:item->second],kill[t].killer.c_str());
			}
			else
				blood.insert(make_pair(kill[t].killer,1));
			if( (item = blood.find(kill[t].victim)) != blood.end() )
				item->second = 0;
			if( (iter = bcount.find(kill[t].killer)) != bcount.end() )
			{
				if(  kill[t].time-iter->second.first <= 14 )
				{
					iter->second.first = kill[t].time;
					iter->second.second += 1;
					if( iter->second.second >= 2 )
						printf(tripkill[iter->second.second>=3?3:iter->second.second],kill[t].killer.c_str());
				}
				else
					iter->second = make_pair(kill[t].time,1);
			}
			else
				bcount.insert(make_pair(kill[t].killer,make_pair(kill[t].time,1)));
		}
		printf("\n");
		blood.clear();
		kill.clear();
		bcount.clear();
	}
	return 0;
}