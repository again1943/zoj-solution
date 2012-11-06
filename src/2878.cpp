#include <cstdio>
#include <limits>
#include <algorithm>

int main()
{
	int n,i,x,y,k;
	int min,max;
	scanf("%d",&n);
	for( i = 0; i < n; i++ ){
		scanf("%d",&x);		
		min = std::numeric_limits<int>::max();
		max = std::numeric_limits<int>::min();
		for( k = 0; k < x; k++ ){
			scanf("%d",&y);
			min = std::min(y,min);
			max = std::max(y,max);
		}
		printf("%d\n",(max-min)*2);
	}
	return 0;
}
