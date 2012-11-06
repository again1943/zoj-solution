/*
 * =====================================================================================
 *
 *       Filename:  acm1582.cpp
 *
 *    Description:  solution to zoj 1582
 *    
 *    ZOJ stands for Zhejiang University Online Judge(http://acm.zju.edu.cn)
 *
 *        Version:  1.0
 *        Created:  2007年03月12日 05时12分21秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<string>
#include<iostream>

using namespace std;

inline int find_first_different( string& first, string& second )
{
	size_t i = 0;
	while( first[i] == second[i]&& 
			i != first.size()&& i != second.size())
		i++;
	return (int)i;
}
int main()
{
	int n;
	int t;
	int pos;
	string correct,wrong;

	cin >> n;

	for( int i = 0; i < n; i++ )
	{
		cin >> t;
		getchar();
		getline(cin,correct);
		getline(cin,wrong);
		pos = find_first_different(correct,wrong);	
		printf("%d\n",(wrong.size()+correct.size()-2*pos)*t);
	}

	return 0;
}
