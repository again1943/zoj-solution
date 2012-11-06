/*
 * =====================================================================================
 *
 *       Filename:  2138.cpp
 *
 *    Description:  solution to zoj 2138
 *
 *        Version:  1.0
 *        Created:  2007年04月28日 00时04分33秒 CST
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


int main()
{
	int n,p;
	int test_case;
	int simple,hard;

	std::vector<int> rank;
	std::vector<std::pair<int,int> >problems;

	std::cin >> test_case;

	for( int i = 0; i < test_case; i++ )
	{
		getchar();
		std::cin >> n >> p;	
		problems.resize(p);
		
		for( int j = 0; j < problems.size();j++ )
			problems[j] = std::make_pair(0,0); 
		for( int j = 0; j < n; j++ )
		{
			rank.resize(p);
			std::cin >> rank[0];
			simple = hard = rank[0];

			for( int k = 1; k < p; k++ )
			{
				std::cin >> rank[k];	
				if( simple > rank[k] )
					simple = rank[k];
				if( hard < rank[k] )
					hard = rank[k];
			}

			for( int k = 0; k < p; k++ )
			{
				if( rank[k] == simple )
					problems[k].first++;
				if( rank[k] == hard )
					problems[k].second++;
			}
			rank.clear();
		}

		if( i >= 1 )
			std::cout << std::endl;
		int count = 0; 
#ifdef DEBUG
		std::cout << "----------------------------" << std::endl;
		for( int j = 0; j < problems.size(); j++ )
			std::cout << "("<<problems[j].first << ","<<problems[j].second <<")";
		std::cout << std::endl;
		std::cout << "----------------------------" << std::endl;
#endif
		for( int j = 0; j < problems.size(); j++ )
			if( problems[j].first >= (1+n)/2 && problems[j].second == 0)
			{
				count++;
				if( count == 1 )
					std::cout << 1+j;
				else
					std::cout << " " << 1+j;
			}
		std::cout << ((count==0)?"0":"") << std::endl;
		problems.clear();
	}

	return 0;
}



