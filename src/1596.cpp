/*
 * =====================================================================================
 *
 *       Filename:  1596.cpp
 *
 *    Description:  solution to zoj 1596
 *
 *        Version:  1.0
 *        Created:  2007年05月07日 19时13分48秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<vector>
#include<utility>
#include<iostream>
#include<algorithm>

long long humble_number(std::vector<int>& prime_list,std::vector<long long>&output,int n)
{
	int index = 0;
	long long top_elem,temp;

	std::pair<int,long long>min_elem;

	std::vector<int>pindex(prime_list.size());
	std::fill(pindex.begin(),pindex.end(),0);

	output.resize(n);
	output[index++] = 1;

	while( index < n )
	{
		top_elem = output[index-1];	
		//min_elem = std::make_pair(0,prime_list[0]*output[pindex[0]]);
		bool flag = false;
		for( size_t i = 0; i < prime_list.size(); i++ )
		{
			temp = prime_list[i]*output[pindex[i]];
			if( flag == false )
			{
				if( temp > top_elem )
				{
					flag = true;
					min_elem = std::make_pair(i,temp);
				}
			}
			else
			{
				if( temp < min_elem.second && temp > top_elem )
					min_elem = std::make_pair(i,temp);
			}
		}
		output[index++] = min_elem.second;
		for( size_t i = 0;i < pindex.size(); i++ )
		{
			while( prime_list[i]*output[pindex[i]] <= min_elem.second )
				pindex[i]++;
		}
#ifdef DEBUG
		std::cout << "index = " << index-1 << ",output = " 
			<< output[index-1] <<std::endl;
		for( size_t i = 0;i  < pindex.size(); i++ )
			std::cout << pindex[i] << " ";
		std::cout << std::endl;
#endif
	}
#ifdef DEBUG
	for( int i = 0; i < index; i++ )
	{
		std::cout << output[i] << " ";
		if( (i+1)%10 == 0 )
			std::cout << std::endl;

	}
#endif
	return output[index-1];
}

int main()
{
	int index;
	std::vector<long long>output;
	std::vector<int>prime_list(3);		
	while( std::cin >> prime_list[0] >> prime_list[1] >> prime_list[2] >> index )
		std::cout << humble_number(prime_list,output,index+1) << std::endl;
	return 0;
}
