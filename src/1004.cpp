#include<cstdio>
#include<cstring>
#define TEXT_LEN 16

char source[TEXT_LEN];
char target[TEXT_LEN];
char step[TEXT_LEN*2];
int step_len,src_len,tar_len,n;

class stack
{

private:
	char s[TEXT_LEN*4];	
	int top_;
public:
	stack()
	{
		top_ = -1;
	}
	char top()	
	{
		return s[top_];	
	}
	void pop()
	{
		top_--;
	}
	void push( char c )
	{
		s[++top_] = c;	
	}
	bool empty()
	{
		return top_ == -1;
	}
};

void bfs( stack &S, int n )
{
	int i;
	char c;	
	if( tar_len == n )
	{
		for( i = 0; i < step_len; i++ )			
			printf("%c ",step[i]);
		printf("\n");
	}
	if( src_len < n )	
	{
		S.push(source[src_len++]);	
		step[step_len++] = 'i';
		bfs(S,n);	
		S.pop();
		src_len--;	
		step[step_len--];
	}
	if( S.empty() != true )
	{
		if( (c = S.top()) == target[tar_len] )	
		{
			S.pop();	
			tar_len += 1;
			step[step_len++] = 'o';
			bfs(S,n);
			step_len--;
			tar_len--;
			S.push(c);
		}
	}
}
int main()
{
	stack S;
	while(scanf("%s%s",source,target) != -1)	
	{
		printf("[\n");
		if((n = strlen(source)) == strlen(target))
		{
			src_len = tar_len = 0;
			step_len = 0;
			bfs(S,n);
		}
		printf("]\n");
	}
	return 0;
}




