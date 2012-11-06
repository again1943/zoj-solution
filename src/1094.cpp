#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

#define CHAR 1
#define RET 2
#define MAX_MT 26
#define LINE_LEN 128

struct matrix_t
{
	int row;
	int col;
}MTX[MAX_MT]; 

struct ret_t
{
	int row;	
	int col;
	int mul;
};

struct stack_t
{
	union
	{
		ret_t ret;
		char c;
	}elem;
	int type;
};

char line[LINE_LEN];
stack_t stack[MAX_MT];

int do_work(char* line )
{
	int top = -1;
	matrix_t mtx;
		
	for( int i = 0; line[i] != '\0'; i++ )
	{
		if( line[i] == '(' )		
		{
			top++;	
			stack[top].type = CHAR;
			stack[top].elem.c = line[i];
		}
		else if( line[i] >= 'A' && line[i] <= 'Z' )
		{
			mtx = MTX[line[i]-'A'];	
			if( top < 0 || stack[top].type == CHAR )
			{
				++top;	
				stack[top].type = RET;
				stack[top].elem.ret.row = mtx.row;
				stack[top].elem.ret.col = mtx.col;
				stack[top].elem.ret.mul = 0;
			}
			else
			{
				if( stack[top].elem.ret.col != mtx.row )
					return -1;
				stack[top].elem.ret.mul += stack[top].elem.ret.row*mtx.row*mtx.col;
				stack[top].elem.ret.col = mtx.col;
			}
		}
		else
		{
			if( top == 1 || stack[top-2].type == CHAR )
			{
				stack[top-1] = stack[top];
				top--;
			}
			else
			{
				stack[top-2].elem.ret.mul += 
					stack[top].elem.ret.mul+
					stack[top-2].elem.ret.row*
					stack[top].elem.ret.row*
					stack[top].elem.ret.col;
				stack[top-2].elem.ret.col = stack[top].elem.ret.col;
				top -= 2;
			}
		}
	}
	return stack[0].elem.ret.mul;
}
int main()
{
	char c;
	int ret;
	int n,row,col;
	scanf("%d",&n);
	for( int i = 0; i < n; i++ )
	{
		getchar();
		scanf("%c%d%d",&c,&row,&col);
		MTX[c-'A'].row = row;
		MTX[c-'A'].col = col;
	}
	while(scanf("%s",line) != -1)
	{
		if( (ret = do_work(line)) < 0 )
			printf("error\n");
		else
			printf("%d\n",ret);
	}
	return 0;
}
