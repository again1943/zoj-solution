#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ElementType char
#define PREORDER -1
#define INORDER	0
#define POSTORDER 1

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
/*Positiddddon FindMin( SearchTree T );*/
/*Position FindMax( SearchTree T );*/
SearchTree MakeEmpty( SearchTree T );
Position Find( ElementType X, SearchTree T );
SearchTree Insert( ElementType X, SearchTree T );
/*/SearchTree Delete( ElementType X, SearchTree T );*/

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty( SearchTree T )
{
	if( T != NULL )
	{
		MakeEmpty( T->Left );
		MakeEmpty( T->Right );
		free( T );
	}
	
	return NULL;
}

SearchTree Insert( ElementType X, SearchTree T )
{
	if( T == NULL )
	{
		T = ( SearchTree )malloc( sizeof( struct TreeNode ) );
		if( T != NULL )
		{
			T->Element = X;
			T->Left = T->Right = NULL;
		}
	}
	
	else if( X < T->Element )
		T->Left = Insert( X, T->Left );
	else if( X > T->Element )
		T->Right = Insert( X, T->Right );
	return T;
}


void Print( const SearchTree T, int order )
{
	if( T != NULL )
	{
		if( order == PREORDER )
		{
			printf("%c",T->Element);
			Print( T->Left,order );
			Print( T->Right,order );
		}
		if( order == INORDER )
		{
			Print( T->Left,order );
			printf("%c",T->Element);
			Print( T->Right,order);
		}
		if( order == POSTORDER )
		{
			Print( T->Left, order );
			Print( T->Right, order );
			printf("%c",T->Element);
		}
	}
}

int FindPos( const char* line, char c,int begin, int len )
{
	int i;
	for( i = begin; i < begin + len; i++ )
		if( line[i] == c )
			return i;
	return begin+len;
}

SearchTree GetResult( SearchTree T,const char* pre, const char* ino, 
		int pre_start, int ino_start,int len  )
{
	int RootPos;
	int NewLen;
	/*int Root;*/
	if( len ==0 )
		return T;
	else if( len == 1 )
		return Insert( pre[pre_start],T );
	else
	{
		RootPos = FindPos( ino,pre[pre_start],ino_start,len );
		T = Insert( pre[pre_start],T );
		if( RootPos == ino_start )
			T->Right = GetResult( T->Left,pre,
					ino,pre_start+1,ino_start+1,len-1);
		else if( RootPos == ino_start+len-1)
			T->Left = GetResult( T->Left,pre,ino,pre_start+1,ino_start,len-1);
		else
		{
			/*Root = FindPos( pre,ino[RootPos+1],pre_start,len);*/
			NewLen = RootPos-ino_start;
			T->Left = GetResult(T->Left,pre,ino,pre_start+1,ino_start,NewLen);
			T->Right = GetResult( T->Right,pre,ino,pre_start+NewLen+1,RootPos+1,len-NewLen-1);
		}
		return T;
	}
}
int main()
{
	char preorder[30],inorder[30];
	int len;
	SearchTree T = NULL;;
	while( scanf("%s%s",preorder, inorder ) != EOF )
	{
		/*T = NULL;*/
		len = strlen( preorder );
		T = GetResult( T,preorder,inorder,0,0,len );
		Print( T,POSTORDER );
		printf("\n");
		T = MakeEmpty( T );
	}

	return 0;
}
