#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAX_NODE 33000
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))

int nindex,root, xmin,ymin,xmax,ymax;
struct qtree_t
{
	int x,y,p,t; //x, y for corrd, p for people, t for total	
	int child[4];
}qnode[MAX_NODE];

inline int idx( int x, int y, int x0, int y0 )
{
	if( x <= x0 && y <= y0 )	
		return 0;	
	if( x >= x0 && y >= y0 )
		return 3;
	if( x < x0 && y > y0 )	
		return 1;
	else
		return 2;
}

int insert(int x, int y, int p, int root)
{
	int i;
	struct qtree_t* pnode;
	if( root == -1 )			
	{
		root = nindex++;	
		pnode = &qnode[root];
		pnode->x = x;
		pnode->y = y;
		pnode->p = p;
		pnode->t = p;
		pnode->child[0] = pnode->child[1] = pnode->child[2] = pnode->child[3] = -1;
	}
	else
	{
		pnode = &qnode[root];
		pnode->t += p;
		if( x == pnode->x && y == pnode->y )
			pnode->p += p;	
		else
		{
			i = idx(x,y,pnode->x,pnode->y);
			pnode->child[i] = insert(x,y,p,pnode->child[i]);
		}
	}
	return root;
}
int query(int x1, int y1, int x2, int y2, int root)
{
	int ret = 0;	
	struct qtree_t* pnode;
	if( root == -1 || x2 < xmin || y2 < ymin || x1 > xmax || y1 > ymax ) // for empty node or out of range
		return 0;

	pnode = &qnode[root];

	if( x1 >= xmin && y1 >= ymin && x2 <= xmax && y2 <= ymax )
		return pnode->t;

	if( pnode->x >= xmin && pnode->x <= xmax && pnode->y >= ymin && pnode->y <= ymax )
		ret += pnode->p;
											
	if( pnode->child[0] != -1 )	
		ret += query(x1,y1,pnode->x,pnode->y,pnode->child[0]);
	if( pnode->child[1] != -1 )
		ret += query(x1,pnode->y,pnode->x,y2,pnode->child[1]);
	if( pnode->child[2] != -1 )
		ret += query(pnode->x,y1,x2,pnode->y,pnode->child[2]);
	if( pnode->child[3] != -1 )
		ret += query(pnode->x,pnode->y,x2,y2,pnode->child[3]);
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
				root = insert(x,y,p,root);
				x1 = min(x1,x);
				y1 = min(y1,y);
				x2 = max(x2,x);
				y2 = max(y2,y);
			}
			else
			{
				sscanf(line,"%d%d%d%d",&xmin,&xmax,&ymin,&ymax);
				printf("%d\n",query(x1,y1,x2,y2,root));
			}
		}
	}
	return 0;
}

