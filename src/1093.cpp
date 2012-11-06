#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_OBJ 1800

int height[MAX_OBJ];
struct object_t
{
	int x,y,z;
}pool[MAX_OBJ];

struct sort_t
{
	bool operator()(const object_t& first, const object_t& second)
	{
		return first.x < second.x;
	}
};


int do_all(int n)
{
	int max_height,i,j;

	sort(pool,pool+n,sort_t());
	max_height = height[0] = pool[0].z;

	for( i = 1; i < n; i++ )
	{
		height[i] = pool[i].z;	
		for( j = 0; j < i; j++ )
		{
			if( pool[i].x > pool[j].x && pool[i].y > pool[j].y && 
						height[i] < height[j]+pool[i].z )			
				
				height[i] = height[j]+pool[i].z;
		}
		max_height = max_height > height[i] ? max_height:height[i];
	}
	return max_height;
}
int main()
{
	int c = 0;
	int n,i,idx;
	while( scanf("%d",&n) && n != 0 )
	{
		for( i = idx = 0; i < n; i++,idx += 6 )				
		{
			scanf("%d%d%d",&pool[idx].x,&pool[idx].y,&pool[idx].z);

			pool[idx+1] = pool[idx];
			swap(pool[idx+1].x,pool[idx+1].y);

			pool[idx+2] = pool[idx+1];
			swap(pool[idx+2].x,pool[idx+2].z);

			pool[idx+3] = pool[idx+2];
			swap(pool[idx+3].x,pool[idx+3].y);

			pool[idx+4] = pool[idx+3];
			swap(pool[idx+4].x,pool[idx+4].z);

			pool[idx+5] = pool[idx+4];
			swap(pool[idx+5].x,pool[idx+5].y);

		}
		printf("Case %d: maximum height = %d\n",++c,do_all(idx));
	}
	return 0;
}
