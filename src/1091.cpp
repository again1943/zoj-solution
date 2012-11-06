#include<cstdio>
#include<utility>
#include<cstdlib>
#include<queue>
using namespace std;

int step[8][2] = {{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1},{-1,2}};

inline bool inside( int x, int y )
{
	return ( x>= 0 && x < 8 && y >= 0 && y < 8 ); 
}


int bfs( int x,int y, int u, int v )
{
	int dep = 0;
	int tx,ty;
	int board[8][8];	
	pair<int,int> pos;
	memset(board,-1,sizeof(board));
	queue<pair<int,int> >X,Y;
	queue<pair<int,int> >* m;
	queue<pair<int,int> >* n;

	board[x][y] = 0;
	m = &X;
	n = &Y;

	m->push(make_pair(x,y));

	while( board[u][v] == -1 )
	{
		dep++;
		while( m->empty() != true )					
		{
			pos = m->front();	
			m->pop();
			for( int i = 0; i < 8; i++ )
			{
				tx = pos.first+step[i][0];
				ty = pos.second+step[i][1];
				if( inside(tx,ty) == true && board[tx][ty] < 0 )
				{
					n->push(make_pair(tx,ty));
					board[tx][ty] = dep;
				}
			}
		}
		swap(m,n);
	}
	return board[u][v];
}
int main()
{
	char ax[3],bx[3];		
	while(scanf("%s%s",ax,bx) != -1)
		printf("To get from %s to %s takes %d knight moves.\n",
			ax,bx,bfs(ax[0]-'a',ax[1]-'1',bx[0]-'a',bx[1]-'1'));	
	return 0;
}
