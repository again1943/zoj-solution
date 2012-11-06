#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
#define BIT_SIZE 101

bool dfs( int v,bitset<BIT_SIZE>&mask )
{
	int i;
	bool ret;
	bitset<BIT_SIZE>mask_cpy;
	if( v == 1 )
		return true;
	for( i = 2; i < BIT_SIZE; i++ )
	{
		if( mask[i] == false && v % i == 0 )
		{
			mask_cpy = mask;	
			mask_cpy[i] = true;	
			if( (ret = dfs(v/i,mask_cpy)) == true )	
				return true;	
		}
	}
	return false;
}

bool dfs_( int x, int y,bitset<BIT_SIZE>&mask )
{
	int i;	
	bool ret;
	bitset<BIT_SIZE>mask_cpy;
	if( x == 1 )
	{
		mask_cpy = mask;
		return dfs(y,mask_cpy);
	}
	else
	{
		for( i = 2; i < BIT_SIZE; i++ )		
		{
			if( mask[i] == false && x % i == 0 )	
			{
				mask_cpy = mask;
				mask_cpy[i] = true;
				if( (ret=dfs_(x/i,y,mask_cpy)) == true )
					return true;
			}
		}
	}
	return false;
}

int main()
{
	int x,y;
	int min_,max_,last;
	bool max_ret,min_ret;
	bitset<BIT_SIZE>mask;
	while(scanf("%d%d",&x,&y) != -1)
	{
		mask.reset();
		min_ = min(x,y);
		max_ = max(x,y);
		if((min_ret = dfs(min_,mask )) == true &&(max_ret = dfs( max_,mask )) == false )
			last = min_;
		else if( min_ret == false )
			last = max_;	
		else
			last = dfs_(min_,max_,mask)?max_:min_;
		printf("%d\n",last);
	}
	return 0;
}
