#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
char boards[2][4][4];
int step[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

bool deal_input()
{
	char c;
	int col = 0;
	int row = 0;
	char *x,*y;
	while( row < 4 )
	{
		x = boards[0][row];
		y = boards[1][row];
		if( (c = getchar() )== '#' )
			return false;
		if( c < 'A' || c > 'Z' )
			continue;
		if( col < 4 )
			x[col++] = c;	
		else
		{
			y[col-4] = c;
			col += 1;
		}
		if( col == 8 ) 
		{
			col = 0;
			row += 1;
		}
	}
	return true;	
}

inline bool inside( int m,int n, int x,int y )
{
	return (x >= 0 && x < m && y >= 0 && y < n );	
}
inline bool vowel( char c )
{
	return (c == 'A' || c == 'E' || c == 'I' 
		|| c == 'O' || c == 'U' || c == 'Y' );
}
bool cover[4][4];
set<string> S,T;
void dfs( int x, int y, int n, char board[][4],string& word,int vcount, int style )
{
	int a,b,i;	
	cover[x][y] = false;		
	word.push_back(board[x][y]);
	if( vowel(board[x][y]) )
		vcount += 1;
	if( word.size() == 4 )
	{
		if( vcount == 2 )
		{
			if( style == 0 )	
				S.insert(word);	
			else
			{
				if( S.find(word) != S.end()&& T.find(word) == T.end())	
					T.insert(word);
			}	
		}
		goto here;
	}
	if( word.size() == 3 && vcount == 0 || vcount > 2 )
		goto here;
	for( i = 0; i < 8; i++ )	
	{
		a = x+step[i][0];
		b = y+step[i][1];
		if( inside(n,n,a,b) && cover[a][b] )
			dfs(a,b,n,board,word,vcount,style);	
	}
here:
	cover[x][y] = true;
	word.erase(word.size()-1);
	if( vowel(board[x][y]) )
		vcount -= 1;
}

int main()
{
	int i,j;
	int t = 0;
	string word;
	while( deal_input() )		
	{
		if( t++ )
			cout << endl;
		S.clear();
		T.clear();
		for( i = 0; i < 4; i++ )	
		for( j = 0; j < 4; j++ )
		{
			word.clear();
			memset(cover,1,sizeof(cover));	
			dfs(i,j,4,boards[0],word,0,0);
		}
		for( i = 0; i < 4; i++ )	
		for( j = 0; j < 4; j++ )
		{
			word.clear();
			memset(cover,1,sizeof(cover));	
			dfs(i,j,4,boards[1],word,0,1);
		}
		if( T.size() == 0 )
			cout << "There are no common words for this pair of boggle boards." << endl;
		else
		{
			for( set<string>::iterator iter = T.begin(); iter != T.end(); ++iter )
				cout << *iter << endl;
		}
	}
	return 0;
}

