/*
 * =====================================================================================
 *
 *       Filename:  2240.cpp
 *
 *    Description:  solution to zoj 2240
 *
 *        Version:  1.0
 *        Created:  2007年04月28日 07时12分41秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<vector>
#include<iostream>
#include<string>
#include<utility>
#include<sstream>

void run_length(std::string& line,std::ostringstream& output)
{
	std::pair<bool,std::size_t>state = std::make_pair(false,0);
	if( line.size() == 0 )
	{
		output.str("");	
		return; 
	}

	for( std::size_t i = 1; i < line.size(); i++ )
	{
		if( state.first == false && line[i] == line[i-1] )
		{
			state.first = true;
			if( state.second < i-1 )
			{
				output << "1";
				while( state.second < i-1 )
				{
					if( line[state.second] == '1')	
						output << "1";
					output << line[state.second++];
				}
				output << "1";
				
			}
		}
		if( state.first == true && line[i] != line[i-1])
		{
			state.first = false;
			for( std::size_t j = 0; j < (i-state.second)/9; j++ )
				output << "9" << line[i-1];
			if( (i-state.second)%9 > 1 )
				output << (i-state.second)%9 << line[i-1];
			if( (i-state.second)%9 == 1 )
			{
				output << "1" << ((line[i-1] == '1')?"1":"") << line[i-1] << "1";
			}
			state.second = i;
		}
	}

	if( state.first == false )
	{
		output << "1";
		while( state.second < line.size())
		{
			if( line[state.second] == '1')	
				output << "1";
			output << line[state.second++];
		}
		output << "1";
	}
	else
	{
		for( std::size_t j = 0; j < (line.size()-state.second)/9; j++ )
			output << "9" << line[state.second];
		if( (line.size()-state.second)%9 > 1 )
			output << (line.size()-state.second)%9 << line[line.size()-1];
		if( (line.size()-state.second)%9 == 1 )
			output << "1" << ((line[line.size()-1] == '1')?"1":"") << line[line.size()-1] << "1";

	}
}
int main()
{
	std::ostringstream output;
	std::string line;	
	while( std::getline(std::cin,line))
	{
		run_length(line,output);	
		std::cout << output.str() << std::endl;
		output.str("");
	}
	return 0;
}

