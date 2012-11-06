#include<cstdio>
#include<cstring>
#include<utility>
#include<queue>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_VALUE 3004

pair<int,int>val[MAX_VALUE];
priority_queue<int,vector<int>,less<int> >Q;

int main()
{
	pair<int,int>last,current;
	int test_case,i,j,k,n,m,time,item,t,total,x,y;	
	scanf("%d",&test_case);
	for(k = 0; k < test_case; k++ )
	{
		t = total = 0;
		scanf("%d%d%d",&n,&m,&time);
		for( i = 0; i < n; i++ )
		for( j = 0; j < m; j++ )
		{
			scanf("%d",&item);
			if( item != 0 )
			{
				Q.push(item);	
				val[item] = make_pair(i,j);
			}
		}
		if( Q.empty() == true )
		{
			total = 0;
			goto end;
		}
		item = Q.top();
		last = val[item];
		if( 2*last.first + 3> time )
		{
			total = 0;
			goto end;
		}
		total += item;
		t += last.first+2;
		Q.pop();
		if( Q.empty() == true )
			goto end;
		while( 1 )
		{
			if( Q.empty() == true )
				goto end;
			item = Q.top();
			Q.pop();
			current = val[item];
			x = abs(last.first-current.first);
			y = abs(last.second-current.second);
			if( t+x+y+current.first+2 > time )
				goto end;
			t += x+y+1;
			total += item;
			last = current;
		}
	end:
		while( Q.empty() != true )
			Q.pop();
		printf("%d\n",total);
	}
	return 0;
}
