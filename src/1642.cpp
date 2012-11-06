#include<iostream>
#include<string>
#include<utility>
#include<map>
#define SIZE 2048
using namespace std;

int cost[SIZE][SIZE];
map<char,int>ch;
int max_value( const char* X, const char* Y )
{
	int len_x = strlen(X)-1;
	int len_y = strlen(Y)-1;
	map<char,int>::iterator pos;
	for( int i = 1; i <= len_x;i++ )
		for( int j = 1 ; j <= len_y ; j++ )
		{
			if( X[i] == Y[j] )
			{	
				pos = ch.find(X[i]);
				cost[i][j] = cost[i-1][j-1] + pos->second;
			}
			else 
				cost[i][j] = cost[i-1][j] >= cost[i][j-1]? cost[i-1][j]:
					cost[i][j-1];
		}
	return cost[len_x][len_y];
}
int main()
{
	pair<char,int> temp;
	char X[SIZE]={'a'};
	char Y[SIZE]={'a'};
	int chnum;
//	for( int i = 0; i < SIZE; i++ )
//	{
//		cost[i][0] = 0;
//		cost[0][i] = 0;
//	}
	while( cin >> chnum )
	{
		for( int i = 0; i <chnum;i++ )
		{
			cin >> temp.first >> temp.second;
			ch.insert( temp );
		}
		cin >> X+1 >> Y+1;
		printf("%d\n",max_value(X,Y));
		ch.clear();
	}
}
