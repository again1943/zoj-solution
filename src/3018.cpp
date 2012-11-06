#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NODE 33000
#define min(x,y) ((x)>(y)?(y):(x))
#define max(x,y) ((x)>(y)?(x):(y))

int nindex,root,xmin,xmax,ymin,ymax;
struct kdtree_t
{
	int x, y,p,h,total,left,right;		
}kdnode[MAX_NODE];

int insert(int x, int y, int p,int h,int root)
{
	if( root == -1 )	
	{
		root = nindex++;
		kdnode[root].x = x;
		kdnode[root].y = y;
		kdnode[root].p = p;
		kdnode[root].h = h;
		kdnode[root].total = p;
		kdnode[root].left = kdnode[root].right = -1;
	}
	else
	{
		if( x == kdnode[root].x && y == kdnode[root].y )	
		{
			kdnode[root].p += p;		
			kdnode[root].total += p;
		}	
		else
		{
			kdnode[root].total += p;
			if( kdnode[root].h % 2 == 0 )			
			{
				if( x <= kdnode[root].x )
					kdnode[root].left = insert(x,y,p,h+1,kdnode[root].left);
				else
					kdnode[root].right = insert(x,y,p,h+1,kdnode[root].right);
			}
			else
			{
				if( y <= kdnode[root].y)
					kdnode[root].left = insert(x,y,p,h+1,kdnode[root].left);
				else
					kdnode[root].right = insert(x,y,p,h+1,kdnode[root].right);
			}
		}
	}
	return root;
}

int query( int x1, int x2, int y1, int y2, int root)
{
	int ret = 0;		
	struct kdtree_t* pnode;
	if( root == -1 )
		return 0;
	pnode = &kdnode[root];
	if( pnode->x >= xmin && pnode->x <= xmax && pnode-> y >= ymin && pnode->y <= ymax )
		ret = pnode->p;
	if( pnode->left == -1 && pnode->right == -1 )
		return ret;
	if( x1 >= xmin && y1 >= ymin && x2 <= xmax && y2 <= ymax )
		return pnode->total;
	if( x2 < xmin || y2 < ymin || x1 > xmax || y1 > ymax )
		return 0;
	if( pnode->h % 2 == 0 )		
	{
		if( pnode->x >= x1 && pnode->x <= x2  )
			return ret + query(x1,pnode->x,y1,y2,pnode->left)+query(pnode->x,x2,y1,y2,pnode->right);
	}
	else
	{
		if( pnode->y >= y1 && pnode->y <= y2 )	
			return ret + query(x1,x2,y1,pnode->y,pnode->left)+query(x1,x2,pnode->y,y2,pnode->right);
	}
	return ret;
}
int main()
{
	char line[128];	
	int x,y,p,x1,x2,y1,y2,mode;
	root = -1;
	nindex = 0;
	x1 = y1 = 0xfffffff;
	x2 = y2 = 0;


	while( gets(line) != NULL )
	{
		if( strcmp(line,"I" ) == 0 )	/* for input */
			mode = 0; 
		else if( strcmp(line,"Q") == 0 ) /* for query */
			mode  = 1; 
		else if( strcmp( line,"E" ) == 0 ) /* end one case */
		{
			root = -1;
			nindex = 0;
			x1 = y1 = 0xfffffff;
			x2 = y2 = 0;
		}
		else /* for data coming */
		{
			if( mode == 0 )	
			{
				sscanf(line,"%d%d%d",&x,&y,&p);
				root = insert(x,y,p,0,root);
				x1 = min(x1,x);
				y1 = min(y1,y);
				x2 = max(x2,x);
				y2 = max(y2,y);
			}
			else
			{
				sscanf(line,"%d%d%d%d",&xmin,&xmax,&ymin,&ymax);
				printf("%d\n",query(x1,x2,y1,y2,root));
			}
		}
	}
	return 0;
}

