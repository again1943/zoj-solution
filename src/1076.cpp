#include<cstdio>
#include<utility>
#include<algorithm>
using namespace std;

#define SEG_SIZE 1024
struct seg_t
{
	int r;	
	int x;
	int y;
}gene[SEG_SIZE];

struct comp_t
{
	bool operator()(const seg_t& first, const seg_t& second )
	{
		return first.y < second.y;
	}
};

int result[SEG_SIZE];

int do_perform(int n)
{
	
	int ret = 0;
	int last = 0;
	sort(gene,gene+n,comp_t());

	result[ret++] = gene[0].r;
	for( int i = 1; i < n; i++ )
	{
		if( gene[i].x > gene[last].y )
		{
			result[ret++] = gene[i].r;
			last = i;
		}
	}
	return ret;
}

int main()
{
	int n,ret;	
	while( scanf("%d",&n) && n != 0 )
	{
		for( int i = 0; i < n; i++ )	
		{
			scanf("%d%d",&gene[i].x,&gene[i].y);
			gene[i].r = i+1;
		}
		ret = do_perform(n);

		printf("%d",result[0]);
		for( int i = 1; i < ret; i++ )
			printf(" %d",result[i]);
		printf("\n");
	}
	return 0;
}
