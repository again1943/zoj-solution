/*
 * =====================================================================================
 *
 *       Filename:  1789.cpp
 *
 *    Description:  solution to zoj 1789
 *
 *        Version:  1.0
 *        Created:  2007年05月17日 22时23分52秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#include<stack>
#include<vector>
#include<algorithm>
#define PEOPLE 30001


std::vector<int>graph[PEOPLE];
bool visited[PEOPLE];

int dfs(int n)
{
	int count,temp;
	std::fill(visited,visited+n,false);
	std::stack<int>stack;
	stack.push(0);
	count = 0;
	while( stack.empty() != true )
	{
		temp = stack.top();
		stack.pop();
		if( visited[temp] == false )
		{
			visited[temp] = true;
			count++;
			for( size_t i = 0; i < graph[temp].size(); i++ )
				if( visited[graph[temp][i]] == false )
					stack.push(graph[temp][i]);
		}
	}
	return count;
}
int main()
{
	int n,m;
	int num,temp,root;
	while( scanf("%d%d",&n,&m)&& n > 0 )
	{
		for( int i = 0; i < m; i++ )	
		{
			scanf("%d",&num);	
			scanf("%d",&root);
			for( int i = 1; i < num;i++ ) 
			{
				scanf("%d",&temp);
				graph[root].push_back(temp);
				graph[temp].push_back(root);
			}
		}
		printf("%d\n",dfs(n));
		for( int i = 0;i < n; i++ )
			graph[i].clear();
			
	}
	return 0;
}
