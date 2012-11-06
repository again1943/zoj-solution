/*
 * =====================================================================================
 *
 *       Filename:  1268.cpp
 *
 *    Description:  solution to zoj 1268
 *
 *        Version:  1.0
 *        Created:  2007年04月24日 04时44分01秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Fatrat
 *
 * =====================================================================================
 */
#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
#define MAX_CHILD 15
struct tree_node_t
{
	int root;
	int n_parent;
};

bool test_tree( const std::vector<tree_node_t>& tree )
{
	int i;
	int n_root = 0;
	if( tree.size() == 0 )
		return true;
	for( i = 0; i < tree.size(); i++ )
	{
		if( tree[i].n_parent == 0 )	
			n_root++;
		if( tree[i].n_parent > 1 )
			return false;
		if( n_root > 1 )
			return false;
	}
	if( n_root != 1 )
		return false;
	else
		return true;

}

int main()
{
	int i,test_case;
	tree_node_t temp;
	std::pair<int,int>edgy;
	std::map<int,int>pos_map;
	std::vector<tree_node_t>tree;
	std::map<int,int>::iterator pos;

	test_case = 0;
	std::cin >> edgy.first >> edgy.second;
	while( !(edgy.first < 0 && edgy.second < 0) )
	{

		if( edgy.first == 0 && edgy.second == 0 )	
		{
			std::cout << "Case " << 
				++test_case << " is " <<
				((test_tree(tree) == true )?"":"not ")
				<< "a tree." << std::endl;		
			tree.clear();
			pos_map.clear();

		}
		else
		{
			//deal with the first point of the edgy
			if( (pos = pos_map.find( edgy.first )) == pos_map.end())
			{
				temp.root = edgy.first;	
				temp.n_parent = 0;
				pos_map.insert(std::make_pair(edgy.first,tree.size()));
				tree.push_back(temp);
			}
			//deal with the second point of the edgy
			if( edgy.second > 0 )
			{
				if( (pos = pos_map.find(edgy.second)) == pos_map.end())
				{
					temp.root = edgy.second;
					temp.n_parent = 1;
					pos_map.insert(std::make_pair(edgy.second,tree.size()));	
					tree.push_back(temp);
				}
				else
					tree[pos->second].n_parent++;	
			}
		}
		std::cin >> edgy.first >> edgy.second;
				
	}
	return 0;

}
