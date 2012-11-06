/*
 * =====================================================================================
 *
 *       Filename:  1108.cpp
 *
 *    Description:  solution to zoj 1108
 *
 *        Version:  1.0
 *        Created:  2007年05月04日 19时23分12秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>

struct triple_t
{
	int first;
	int second;
	int third;
};
struct sort_op
{
	bool operator()(const triple_t&one,const triple_t&two)	
	{
		return one.first < two.first;	
	}
};

void longest_increasing_subset(const std::vector<triple_t >&fatmouse,std::vector<int>&output )
{
	int i,j;
	int n = fatmouse.size();
	std::pair<int,int> pos;
	std::vector<std::pair<int,int> >maxlen(n);
	maxlen[0] = std::make_pair(1,-1);
	pos = std::make_pair(1,0);

	for( i = 1; i < n; i++ )
	{
		maxlen[i] = std::make_pair(1,-1);
		for( j = 0; j < i; j++ )
		{
			if( fatmouse[i].second < fatmouse[j].second &&  
					fatmouse[i].first != fatmouse[j].first &&
					maxlen[j].first + 1 > maxlen[i].first )
				maxlen[i] = std::make_pair(maxlen[j].first+1,j);
		}
		if( pos.first < maxlen[i].first )
			pos = std::make_pair(maxlen[i].first,i);
	}
#ifdef DEBUG
	std::cout << "--------------------" << std::endl;
	for( size_t k = 0; k < maxlen.size(); k++ )
		std::cout << maxlen[k].first << " ";
	std::cout << std::endl;
	std::cout << "--------------------" << std::endl; 

#endif
	i = pos.second;
	while( i > 0 )
	{
		output.push_back(i);
		i = maxlen[i].second;
	}
}
int main()
{
	int i = 0;
	triple_t temp;
	std::vector<int> output;
	std::vector<triple_t>fatmouse;
	while( std::cin >> temp.first >> temp.second )
	{
		temp.third = ++i;
		fatmouse.push_back(temp);
	}
	std::sort(fatmouse.begin(),fatmouse.end(),sort_op());
#ifdef DEBUG
	std::cout << "---------------------" << std::endl;
	for( size_t j = 0; j < fatmouse.size(); j++ )
		std::cout << fatmouse[j].first << " " << fatmouse[j].second << std::endl;
	std::cout << "---------------------" << std::endl;
#endif
	longest_increasing_subset(fatmouse,output);
	std::cout << output.size() << std::endl;
	for( i = output.size()-1; i >= 0; i-- )
		std::cout << fatmouse[output[i]].third << std::endl;
#ifdef DEBUG
	std::cout << "---------------------" << std::endl;
	for( int j = output.size()-1; j >= 0; j-- )
		std::cout << fatmouse[output[j]].first << " " << fatmouse[output[j]].second << std::endl;
	std::cout << "---------------------" << std::endl;

#endif
	return 0;
}
