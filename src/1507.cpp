#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <cassert>
using namespace std;

set<unsigned long long>substr;
char line[1024*1024];

int main()
{
	int m,n,nc,i,p,k;
	unsigned long long quad,mask;
	freopen("in3","r",stdin);
	scanf("%d",&m);
	for( i = 0; i < m; i++ )
	{
		scanf("%d%d",&n,&nc);
		scanf("%s",line);
		assert(n <= 12);
		mask = ((~0ULL)>>(sizeof(unsigned long long)*8-5*n));
		for( p = 0,quad = 0; p < n; p++ )
			quad = ((quad<<5)|(line[p]-'a'));
		substr.insert(quad);
		for( p = n; line[p] != 0; p++ )
		{
			quad = ((quad << 5) | (line[p]-'a'))&mask;
			if(substr.find(quad) == substr.end() )
				substr.insert(quad);
		}
		if( i != 0 )
			printf("\n");
		printf("%d\n",substr.size());
		substr.clear();
	}
	return 0;
}




