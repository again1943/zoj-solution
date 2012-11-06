#include<cstdio>
#include<cstring>
#include<map>
#include<utility>
using namespace std;

struct tree_t
{
	char name[32];
};

bool operator<(const tree_t& x,const tree_t& y )
{
	return strcmp(x.name,y.name) < 0;
}
bool operator==(tree_t& x, tree_t& y )
{
	return (strcmp(x.name,y.name) == 0);
}


map<tree_t,int>M;
map<tree_t,int>::iterator iter,end;

int main()
{
	int n,t;
	tree_t tree;

	n = t = 0;
	while( gets(tree.name) != 0)
	{
		if( tree.name[0] == 0 )		
		{
			if( t++ != 0 )	
				printf("\n");
			end = M.end();
			for( iter = M.begin(); iter != end; ++iter )
				printf("%s %0.4lf\n",iter->first.name,100*(iter->second/(double)n));
			n = 0;	
			M.clear();
		}
		else
		{
			n += 1;
			if( (iter = M.find(tree)) != M.end())
				iter->second += 1;	
			else
				M.insert(make_pair(tree,1));
		}
	}
	if( t++ != 0 )	
		printf("\n");
	end = M.end();
	for( iter = M.begin(); iter != end; ++iter )
		printf("%s %0.4lf\n",iter->first.name,100*(iter->second/(double)n));

	return 0;
}
