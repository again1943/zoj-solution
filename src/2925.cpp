#include<cstdio>
#include<queue>
using namespace std;
#define GRID_SIZE 512
char matrix[GRID_SIZE][GRID_SIZE];

inline bool inside(int n, int m, int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

char dir[] = 
{
	//ABCDEFG
	-1,-1,-1,-1,0,-1,-1,
	//HIJKLMN
	-1,-1,5,-1,-1,-1,2,
	//OPQRSTU
	-1,-1,7,-1,6,-1,-1,
	//VWXYZ
	3,4,-1,1,-1
};
int direct[][2] = 
{
	{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}		
};
void do_direct(queue<int>& Q, int n, int m,int r, int c,char d)
{
	int z = dir[d-'A'];
	int x = r + direct[z][0];
	int y = c+direct[z][1];
	if( inside(n,m,x,y) == true && matrix[x][y] == 'X' )		
	{
		matrix[x][y] = d;
		Q.push(x*m+y);
	}
}
void domino( int n, int m, int x, int y,char d)
{
	int r,c,item;
	queue<int>Q;
	matrix[x][y] = d;
	Q.push(x*m+y);
	while( Q.empty() != true )
	{
		item = Q.front();
		Q.pop();
		r = item/m;
		c = item%m;
		switch( matrix[r][c] )
		{
			case 'E':
				do_direct(Q,n,m,r,c,'E');
				do_direct(Q,n,m,r,c,'Y');
				do_direct(Q,n,m,r,c,'Q');
				break;
			case 'Y':
				do_direct(Q,n,m,r,c,'E');
				do_direct(Q,n,m,r,c,'Y');
				do_direct(Q,n,m,r,c,'N');
				break;
			case 'N':
				do_direct(Q,n,m,r,c,'V');
				do_direct(Q,n,m,r,c,'Y');
				do_direct(Q,n,m,r,c,'N');
				break;
			case 'V':
				do_direct(Q,n,m,r,c,'V');
				do_direct(Q,n,m,r,c,'W');
				do_direct(Q,n,m,r,c,'N');
				break;
			case 'W':
				do_direct(Q,n,m,r,c,'V');
				do_direct(Q,n,m,r,c,'W');
				do_direct(Q,n,m,r,c,'J');
				break;
			case 'J':
				do_direct(Q,n,m,r,c,'S');
				do_direct(Q,n,m,r,c,'W');
				do_direct(Q,n,m,r,c,'J');
				break;
			case 'S':
				do_direct(Q,n,m,r,c,'S');
				do_direct(Q,n,m,r,c,'Q');
				do_direct(Q,n,m,r,c,'J');
				break;
			case 'Q':
				do_direct(Q,n,m,r,c,'S');
				do_direct(Q,n,m,r,c,'Q');
				do_direct(Q,n,m,r,c,'E');
				break;
			default:
				break;	
		}
	}
}
int main()
{
	char d;
	int t = 0;
	int x,y,n,m,i;
	while( scanf("%d%d",&n,&m) != -1 )
	{
		for( i = 0; i < n; i++ )	
			scanf("%s",matrix[i]);
		scanf("%d%d %c",&x,&y,&d);
		domino(n,m,x-1,y-1,d);
		if( t++ != 0 )
			printf("\n");
		for( i = 0; i < n; i++ )
			printf("%s\n",matrix[i]);
	}
	return 0;
}
