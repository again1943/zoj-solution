/*
 * =====================================================================================
 *
 *       Filename:  2165.cpp
 *
 *    Description:  solution to zoj 2165
 *
 *        Version:  1.0
 *        Created:  2007年05月05日 09时27分16秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<iostream>
#include<string>
#include<utility>
#include<stack>
#define SIZE 25


int board[SIZE][SIZE];
inline int get_code(char c )
{
	switch(c)
	{
		case '.':
			return 1;
		case '#':
			return -1;
		default:
			return 0;
	}
}
inline int fill_board(const std::string& line, int idx,int w )
{
	int i;
	int store = -1;
	for( i = 0; i < w; i++ )
		if( (board[idx][i] = get_code(line[i])) == 0 )
			store = i;
	return store;
}

int get_result( const std::pair<int,int>& pos,int w,int h) 
{
	int count = 0;
	std::pair<int,int>temp;	
	std::stack<std::pair<int,int> >stack;
	stack.push(pos);
	while( stack.empty() != true )
	{
		temp = stack.top();	
		stack.pop();
#ifdef DEBUG
		std::cout << "Out stack:(" << temp.first  << "," << temp.second << ")" << std::endl;
#endif
		count++;
		board[temp.first][temp.second] = 0;

		if( temp.first + 1 < h && board[temp.first+1][temp.second] == 1 )
		{
			stack.push(std::make_pair(temp.first+1,temp.second));
			board[temp.first+1][temp.second]++;
#ifdef DEBUG
		std::cout << "In stack:(" << temp.first+1 << "," << temp.second << ")" << std::endl;
#endif
		}
		if( temp.first-1 >= 0 && board[temp.first-1][temp.second] == 1 )
		{
			stack.push(std::make_pair(temp.first-1,temp.second));
			board[temp.first-1][temp.second]++;
#ifdef DEBUG
		std::cout << "In stack:(" << temp.first-1 << "," << temp.second << ")" << std::endl;
#endif
		}
		if( temp.second+1 < w && board[temp.first][temp.second+1] == 1 )
		{
			stack.push(std::make_pair(temp.first,temp.second+1));
			board[temp.first][temp.second+1]++;
#ifdef DEBUG
		std::cout << "In stack:(" << temp.first << "," << temp.second+1 << ")" << std::endl;
#endif
		}
		if( temp.second-1 >= 0 && board[temp.first][temp.second-1] == 1 )
		{
			stack.push(std::make_pair(temp.first,temp.second-1));
			board[temp.first][temp.second-1]++;
#ifdef DEBUG
		std::cout << "In stack:(" << temp.first << "," << temp.second-1 << ")" << std::endl;
#endif
		}
	}
	return count;
}
int main()
{
	int t;	
	int w,h;
	std::pair<int,int>pos;
	std::string info;
	while( (std::cin >> w >> h) && ( w != 0 || h != 0 ))
	{
		for( int i = 0; i < h; i++ )		
		{
			std::cin >> info;
			if( (t = fill_board(info,i,w)) >= 0 ) 
				pos = std::make_pair(i,t);
		}
		std::cout << get_result(pos,w,h) << std::endl;
	}
	return 0;
}
