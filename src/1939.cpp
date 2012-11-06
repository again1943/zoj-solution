#include <map>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 128
string words[MAX_SIZE];
int proposal[3][MAX_SIZE];
int field[MAX_SIZE][MAX_SIZE];
int prev[MAX_SIZE][MAX_SIZE];
map<string,int>M;

int step[3][2] = {{0,-1},{-1,-1},{-1,0}};
int lcs(int* a, int na, int* b, int nb,int* c)
{
	int i,j,n,x,y,m;
	memset(field,0,sizeof(field));
	memset(prev,-1,sizeof(prev));
	for( i = 1; i <= na; i++ )
	for( j = 1; j <= nb; j++ )
	{
		if( a[i-1] == b[j-1] )		
		{
			field[i][j] = field[i-1][j-1]+1;
			prev[i][j] = 1;
		}
		else if( field[i-1][j] > field[i][j-1] )
		{
			prev[i][j] = 2;
			field[i][j] = field[i-1][j];
		}
		else
		{
			prev[i][j] = 0;
			field[i][j] = field[i][j-1];
		}
	}
	n = 0;
	x = na;
	y = nb;
	while( (m = prev[x][y]) >= 0 )
	{
		if( a[x-1] == b[y-1] )
			c[n++] = a[x-1];
		x = x+step[m][0];
		y = y+step[m][1];
	}
	reverse(c,c+n);
	return n;
}
int main()
{
	int n[3];
	int i,j,m;
	string word;	
	map<string,int>::iterator item;	
	i = j = m = 0;
	while( cin >> word )
	{
		if( word == "#" )		
		{
			if( i == 0 )		
			{
				i += 1;	
				n[0] = j;
				j = 0;
			}
			else
			{
				n[1] = j;
				n[2] = lcs(proposal[0],n[0],proposal[1],n[1],proposal[2]);	
				cout << words[proposal[2][0]];
				for( i = 1; i < n[2]; i++ )
					cout << " " << words[proposal[2][i]];
				cout << endl;
				i = j = m = 0;	
				M.clear();
			}
		}
		else if( (item = M.find(word)) == M.end() )	
		{
			words[m] = word;		
			M.insert(make_pair(word,m));
			proposal[i][j++] = m++;
		}
		else
			proposal[i][j++] = item->second;
						
	}
	return 0;
}
