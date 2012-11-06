#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_LEN 13
struct elem_t
{
	int n;
	int value;
	int total;
};

elem_t elem[MAX_LEN];

struct stack_t
{
	int stack_ptr;
	int vec[MAX_LEN];
};

bool flag;

void bfs( int idx, int sum, int end,stack_t stack )
{
	int temp;
	stack_t copy;

	if( idx >= end && sum != 0 )
		return;
	
	if( sum == 0 )
	{
		printf("%d",stack.vec[0]);				
		for( int i = 1; i <= stack.stack_ptr; i++ )
			printf("+%d",stack.vec[i]);
		printf("\n");
		flag = true;
		return;
	}

	if( sum > 0 && elem[idx].total >= sum )
	{
		if( elem[idx].value > sum )
			bfs(idx+1,sum,end,stack);
		else
		{
			temp = min(sum/elem[idx].value,elem[idx].n);
			for( int i = temp; i >= 0; i-- )
			{
				copy = stack;
				for( int j = 0; j < i; j++ )
					copy.vec[++copy.stack_ptr] = elem[idx].value;
				bfs(idx+1,sum-i*elem[idx].value,end,copy);
			}
		}
		return;
	}
	return;
}

int main()
{
	int sum,n,temp,idx;
	stack_t first;
	while(scanf("%d%d",&sum,&n) && n != 0 )
	{
		scanf("%d",&elem[idx=0].value);	
		elem[idx++].n = 1;
		for( int i = 1; i < n; i++ )	
		{
			scanf("%d",&temp);
			if( temp == elem[idx-1].value )
				elem[idx-1].n++;
			else
			{
				elem[idx++].value = temp;
				elem[idx-1].n = 1;
			}
		}
		elem[idx].total = 0;
		for( int i = idx-1; i >= 0; i-- )
			elem[i].total = elem[i+1].total+elem[i].n*elem[i].value;
		printf("Sums of %d:\n",sum);
		flag = false;
		first.stack_ptr = -1;
		/*
		for( int i = 0; i < idx && elem[i].total >= sum; i++ )
		{
			if( elem[i].value > sum )	
				continue;
			else
				bfs(i,sum,idx,first);
		}
		*/
		bfs(0,sum,idx,first);
		if( flag == false )
			printf("NONE\n");
	}
	return 0;
}
