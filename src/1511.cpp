#include <cstdio>
#include <cstring>
#include <algorithm>

#define MAXN 1024

char puzzle[MAXN][MAXN];
char words[MAXN][MAXN];

struct word_info_t
{
	bool	find;
	char	dir;
	int		x,y;
	int		size;
}info[MAXN];


const char direct[] = {"ABCDEFGH"};
const int  step[8][2] = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};


inline bool inside(int x, int y, int m, int n)
{
	return (x >=0 && x <= m-1 && y >= 0 && y <= n-1);
}

inline bool do_search(char* wd,int x, int y, int d, int size)
{
	int i;
	bool ret = false;;
	switch(d)
	{
	case 0:
		for( i = 0; i < size; i++ )
			if( puzzle[x-i][y] != wd[i] )
				goto escape;
		ret = true;
		break;
	case 1:
		for( i = 0; i < size; i++ )
			if( puzzle[x-i][y+i] != wd[i] )
				goto escape;
		ret = true;
		break;
	case 2:
		for( i = 0; i < size; i++ )
			if( puzzle[x][y+i] != wd[i] )
				goto escape;
		ret = true;
		break;
	case 3:
		for( i = 0; i < size; i++ )
			if( puzzle[x+i][y+i] != wd[i] )
				goto escape;
		ret = true;
		break;
	case 4:
		for( i = 0; i < size; i++ )
			if( puzzle[x+i][y] != wd[i] )
				goto escape;
		ret = true;
		break;
	case 5:
		for( i = 0; i < size; i++ )
			if( puzzle[x+i][y-i] != wd[i] )
				goto escape;
		ret = true;
		break;
	case 6:
		for( i = 0; i < size; i++ )
			if( puzzle[x][y-i] != wd[i] )
				goto escape;
		ret = true;
		break;
	default:
		for( i = 0; i < size; i++ )
			if( puzzle[x-i][y-i] != wd[i] )
				goto escape;
		ret = true;
		break;
	}
escape:
	return ret;
}
inline int search_word(int m,int n,int a,int b, int c)
{
	int d,x,y,size;
	if( puzzle[a][b] != words[c][0] )
		return -1;
	size = info[c].size;
	for( d = 0; d < 8; d++ )
	{
		x = step[d][0]*(size-1)+a;
		y = step[d][1]*(size-1)+b;

		if( inside(x,y,m,n) && do_search(words[c],a,b,d,size) )
			return d;
	}
	return -1;
}
int main()
{
	int m,n,w,a,b,i,c,d,r,count;

	r = 0;

	//freopen("in6","r",stdin);
	while (scanf("%d%d%d",&m,&n,&w) != -1)
	{
		if( r++ != 0 )
			printf("\n");

		for( i = 0; i < m; i++ )
			scanf("%s",puzzle[i]);
		memset(info,0,sizeof(info));
		for( i = 0; i < w; i++ )
		{
			scanf("%s",words[i]);
			info[i].size = strlen(words[i]);
		}
		
		count = w;
		for( a = 0; a < m; a++ )
		for( b = 0; b < n; b++ )
		{
			if( count == 0 )
				goto escape;
			for( c = 0; c < w; c++ )
			{
				if( info[c].find == true )
					continue;
				if( (d = search_word(m,n,a,b,c)) >= 0 )
				{
					count -= 1;
					info[c].find = true;
					info[c].dir = direct[d];
					info[c].x = a;
					info[c].y = b;
				}
			}
		}
escape:
		for( i = 0; i < w; i++ )
			printf("%d %d %c\n",info[i].x,info[i].y,info[i].dir);
		
	}
	return 0;

}