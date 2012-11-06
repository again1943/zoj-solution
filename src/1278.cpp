#include <utility>
#include <map>
#include <cstdio>

using namespace std;

int evaluate(int z, int i, int m, int l)
{
	int order = 0;
	map<int,int>repeat;
	map<int,int>::iterator iter;
	while ((iter = repeat.find(l))==repeat.end())
	{
		repeat.insert(make_pair(l,order++));
		l = (z*l+i)%m;
	}
	return order-iter->second;
}
int main()
{
	int z,i,m,l;
	int test_case = 1;
	while(scanf("%d%d%d%d",&z,&i,&m,&l)&&(z != 0 || i != 0 || m != 0 || l != 0 ))
		printf("Case %d: %d\n",test_case++,evaluate(z,i,m,l));
	return 0;
}