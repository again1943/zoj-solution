#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_DICE 10004

int dice[MAX_DICE][6];

int find_pos( int* d, int v )
{
	int i;
	for( i = 0; i < 6; i++ )	
		if( d[i] == v )
			break;
	switch(i)	
	{
		case 0:
			return 5;
		case 5:
			return 0;
		case 1:
			return 3;
		case 3:
			return 1;
		case 2:
			return 4;	
		case 4:
			return 2;
		default:
			return -1;
	}
}

int dice_max_with_base( int dice[][6], int n, int base )
{
	int i,j,x,y,pos,retval,elem;
	for( i = retval = 0; i < n; i++ )
	{
		pos = find_pos(dice[i],base);
		x = base;
		y = dice[i][pos];
		for( j = elem = 0; j < 6; j++ )
			if( dice[i][j] != x && dice[i][j] != y )
				elem = max(elem,dice[i][j]);
		retval += elem;
		base = y;
	}
	return retval;
}
int dice_max( int dice[][6], int n )
{
	int i;
	int maxval = 0;
	for( i = 1; i <= 6; i++ )		
		maxval = max(maxval,dice_max_with_base(dice,n,i));
	return maxval;
}
int main()
{
	int n,k,t,i;	
	scanf("%d",&t);
	for( k = 0; k < t; k++ )
	{
		scanf("%d",&n);
		for( i = 0; i < n; i++ )
			scanf("%d%d%d%d%d%d",&dice[i][0],
			&dice[i][1],&dice[i][2],&dice[i][3],
			&dice[i][4],&dice[i][5]);
		printf("%d\n",dice_max(dice,n));
	}
	return 0;
}
