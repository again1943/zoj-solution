#include <cstdio>
#include<queue>
#include<vector>

#define SIZE 5842
#define UPPER_BOUND 2000000000
//#define DEBUG

using namespace std;

vector<int>vec(SIZE+1);
void gen_number()
{
	int index[4] = {1,1,1,1};
	int prime[4] = {2,3,5,7};
	int temp[4];
	int min;
	//int idx;
	vec[1] = 1;

	for(int i = 2; i <= SIZE; i++ )
	{
		for(int j = 0; j < 4; j++ )
			temp[j] = vec[index[j]]*prime[j];
		min = temp[0];
		//idx = 0;
		for( int j = 1; j < 4; j++ )
			if( min > temp[j])
				min = temp[j];
		for( int j = 0; j < 4; j++ )
			if (min == temp[j])
				index[j]++;
		vec[i] = min;
	}
}
void format_index(int index)
{
	if(index%10 == 1 && index%100 != 11 )
		printf("The %dst humble number is %d.\n",index,vec[index]);
	else if(index%10 == 2 && index % 100 != 12 )
		printf("The %dnd humble number is %d.\n",index, vec[index]);
	else if(index%10 == 3 && index%100 != 13 )
		printf("The %drd humble number is %d.\n",index, vec[index]);
	else
		printf("The %dth humble number is %d.\n",index, vec[index]);
}
int main()
{
	int index;
	gen_number();
	while( scanf("%d",&index) && index > 0 )
		format_index(index);
	return 0;
}