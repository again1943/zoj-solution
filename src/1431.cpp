#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;
struct people
{
	char name[25];
	int net_weight;
};
struct oper
{
	bool operator()( const people& first,const people& second )
	{
		return first.net_weight > second.net_weight;
	}
};
int main()
{
	int time = 0;
	int num;
	int day,weight;
	people person[15];
	char info[50];
	
	while( scanf("%s",info) != -1 )
	{
		if( strcmp( info,"START" ) == 0 )
		{	
			time++;
			num = 0;
		}
		else if( strcmp( info,"END") == 0 )
		{
			stable_sort( person,person+num,oper());
			if( time > 1 )
				printf("\n");
			for( int i = 0; i < num; i++ )
				printf("%s\n",person[i].name );
			
		}
		else
		{
			scanf("%d%d",&day,&weight);
			strcpy(person[num].name,info );
			person[num++].net_weight = 
				(weight-day > 1)?(weight-day):1;
		}
	}
	return 0;
}
