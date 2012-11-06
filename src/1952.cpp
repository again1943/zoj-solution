#include<map>
#include<iostream>
#include<cstring>
#include<string>
#include<utility>
using namespace std;
#define MAX_NAME 32
#define MAX_CNT 256
#define INVALID -1
int matrix[MAX_CNT][MAX_CNT];
int dijkstra(int matrix[][MAX_CNT], int n, int s, int e )
{
	int i,j,k,t;
	int w[MAX_CNT],val;
	bool in[MAX_CNT];		
	memset(in,0,sizeof(in));
	memset(w,0,sizeof(w));
	#define LIMIT 0x7fffffff
	w[s] = LIMIT;
	in[k = s] = true;
	for( i = 0; i < n; i++ )
	{
		if(in[i] != true &&  matrix[s][i] >= 0 )
			w[i] = matrix[s][i];	
	}
	while( 1 )
	{
		for( i = 0,t = -1,val = 0; i < n; i++ )
		{
			if( in[i] != true && matrix[k][i] >= 0 && val < w[i] )
			{
				t = i;
				val = w[i];
			}
		}
		if( t < 0 )
			break;
		in[t] = true;
		for( i = 0; i < n; i++ )
		{
			if( in[i] != true && matrix[t][i] >= 0 )
				w[i] = max(w[i],min(w[t],matrix[t][i]));
		}
		k = t;
	}
	return w[e];
}

int main()
{
	int t = 0;
	int index;
	int n,r,i,j,v,a,b,s,e;
	string x,y;
	map<string,int>M;
	map<string,int>::iterator item;
	while( (cin >> n >> r ) && n != 0 )
	{
		index = 0;
		M.clear();
		memset(matrix,-1,sizeof(matrix));
		for( i = 0; i < r; i++ )
		{
			cin >> x >> y >> v;
			if( (item = M.find(x)) == M.end() )
			{
				a = index++;	
				M.insert(make_pair(x,a));
			}
			else
				a = item->second;
			if( (item = M.find(y)) == M.end())
			{
				b = index++;	
				M.insert(make_pair(y,b));
			}
			else
				b = item->second;
			matrix[a][b] = matrix[b][a] = v;
		}
		cin >> x >> y;
		s = M[x];
		e = M[y];
		printf("Scenario #%d\n",++t);
		printf("%d tons\n\n",dijkstra(matrix,n,s,e));
	}
	return 0;
}
