/*
 * =====================================================================================
 *
 *       Filename:  2680.cpp
 *
 *    Description:  solution to zoj 2680
 *
 *        Version:  1.0
 *        Created:  2007年05月01日 06时49分57秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>

struct triple_t
{
	int hour;
	int minute;
	double angle;
};

struct sort_op
{
	bool operator()(const triple_t& first,const triple_t& second)
	{
		if (first.angle != second.angle)
			return first.angle < second.angle;
		return first.hour*60+first.minute < second.hour*60+second.minute;
	}
};

int main()
{
	std::string time;	
	std::vector<triple_t> five(5);
	int test_case,tag;

	std::cin>>test_case;
	while( test_case-- )
	{
		for( int i = 0; i < 5; i++ )	
		{
			std::cin >> time;	
			five[i].hour = (time[0]-'0')*10+(time[1]-'0');
			five[i].minute = (time[3]-'0')*10+(time[4]-'0');
			five[i].angle = fabs(30*(five[i].hour%12)+five[i].minute*30/60.0-6*five[i].minute);
			five[i].angle = five[i].angle >= 180?360-five[i].angle:five[i].angle;
		}
		std::stable_sort(five.begin(),five.end(),sort_op());
#ifdef DEBUG
		for( int i = 0; i < 5; i++ )
			std::cout << "(" << five[i].hour/10 << five[i].hour%10 << ":" 
			<< five[i].minute/10 << five[i].minute%10 << "," 
			<< five[i].angle <<")" <<std::endl;
	
#endif
		tag = 2;
		/*
		if( five[2].angle == five[1].angle )
			tag = 1;
		if( five[2].angle == five[0].angle )
			tag = 0;
			*/
		std::cout << five[tag].hour/10 << five[tag].hour%10 << ":" 
			<< five[tag].minute/10 << five[tag].minute%10 << std::endl;


	}
	return 0;
}

