#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
#define SIZE 32
using namespace std;

struct state_t
{
	int sum;
	int next;
	unsigned int flags;
};
int elem[SIZE];
set<int> int_set;
queue<state_t> state;

inline void set_n( unsigned int& flags, unsigned int n )
{
	flags |= (1<<n);
}
inline bool test_n( unsigned int flags, unsigned int n )
{
	return ((flags&(1<<n)) != 0);
}

void print( state_t& s, int range,int sum)
{
	int i = 0; 
	while( test_n(s.flags,i) == false )
		i++;
	printf("%d",elem[i++]);
	while( i < range )
	{
		if( test_n(s.flags, i) == true )
			printf("+%d",elem[i]);
		i++;
	}
	printf("=%d\n",sum);
}
int main()
{
	int test_case;
	int n_elem;
	int max,temp;
	bool flags;
	state_t S;
	scanf("%d",&test_case);
	for( int i = 0; i < test_case; i++ )
	{
		scanf("%d",&n_elem);
		for( int j = 0; j < n_elem; j++ )
		{
			scanf("%d",&elem[j]);
			int_set.insert(elem[j]);
		}
		sort(elem,elem+n_elem);
		max = elem[n_elem-1];
		flags = false;
		for( int j = 0; j < n_elem-1; j++ )
		for( int k = j+1; (temp  = elem[j]+elem[k] ) <= max; k++ )
		{
			if(  int_set.find(temp) != int_set.end() )
			{
				printf("%d+%d=%d\n",elem[j],elem[k],temp);
				flags = true;
			}
			S.flags = 0;
			S.sum = temp;
			S.next = k+1;
			set_n(S.flags,j);
			set_n(S.flags,k);
			state.push(S);
		}
		while( state.empty() != true )
		{
			state_t new_state;
			S = state.front();
			state.pop();
			for( int j = S.next; j < n_elem&& 
				(temp = S.sum+elem[j]) <= max; j++ )
			{
				new_state = S;
				set_n(new_state.flags,j);
				new_state.next = j+1;
				new_state.sum = temp;
				if( int_set.find( temp ) != int_set.end())
				{
					print(new_state,n_elem,temp);
					flags = true;
				}
				state.push(new_state);
			}
		}
		if( flags == false )
			printf("Can't find any equations.\n");	
		int_set.clear();
		printf("\n");
	}
	return 0;
}
