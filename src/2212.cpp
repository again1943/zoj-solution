/*
 * =====================================================================================
 *
 *       Filename:  2212.cpp
 *
 *    Description:  solution to zoj 2212
 *
 *        Version:  1.0
 *        Created:  2007年04月25日 07时01分16秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars
 *        Company:  Fatrat
 *
 * =====================================================================================
 */

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>


struct argus_t
{
	int query;
	int time_slice;
	int n;
};

/*
struct sort_op
{
	bool operator()(const argus_t& first,const argus_t& second)
	{
		return ((first.time_slice < second.time_slice)||
				(first.time_slice==second.time_slice&&first.query<second.query));
	}
}

*/
int main()
{
	int n;
	int min_time,min_query,min_pos;

	argus_t temp;
	std::string line;
	std::vector<argus_t>argus;	

	std::cin >> line;

	while( line != "#" )
	{
		std::cin >> temp.query >> temp.time_slice;	
		temp.n = 0;	
		argus.push_back(temp);
		std::cin >> line;
	}

	std::cin >> n;	

	for( int i = 0; i < n; i++ )
	{
		min_time = 30000000;
		min_query = 30000000;
		min_pos = -1;
		for( int j = 0; j < argus.size(); j++ )
		{
			if( min_time > (argus[j].n+1)*argus[j].time_slice )	
			{
				min_time = (argus[j].n+1)*argus[j].time_slice;
				min_query = argus[j].query;
				min_pos = j;
			}
			if( min_time == (argus[j].n+1)*argus[j].time_slice && min_query > argus[j].query )
			{
				min_pos = j;
				min_query = argus[j].query;
			}
		}
		argus[min_pos].n++;
		std::cout << min_query << std::endl;
	}
	return 0;


}
