/*
 * =====================================================================================
 *
 *       Filename:  1900.cpp
 *
 *    Description:  solution to zoj 1900 * *        Version:  1.0 *        Created:  2007年10月20日 13时38分51秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<bitset>
#include<vector>
#include<cstdio>

using namespace std;
#define PEOPLE_NUM 101
#define TREE_NUM 101

struct opintion_t
{
	bool same;
	bitset<TREE_NUM> tree_bit;
};

int main()
{
	int c,i,j;
	int p,t;
	int people,tree;
	vector<opintion_t> vec(PEOPLE_NUM);
	while(scanf("%d%d",&people,&tree) != -1)
	{
		getchar();
		while( (c = getchar()) != '\n' && c != EOF )
		{
			ungetc(c,stdin);	
			scanf("%d%d",&p,&t);
			getchar();
			vec[p].same = false;
			vec[p].tree_bit.set(t);
		}

		for( i = 1; i <= people; i++ )
		for( j = i+1; j <= people; j++ )
		{
			if( vec[j].same == true )
				continue;
			if( vec[j].tree_bit == vec[i].tree_bit )
				vec[j].same = true;
		}
		for( i = 1,c = 0; i <= people; i++ )
		{
			if( vec[i].same == false )
				c++;
			vec[i].same = false;	
			vec[i].tree_bit.reset();
		}
		printf("%d\n",c);
	}
	return 0;

}


