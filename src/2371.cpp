/*
 * =====================================================================================
 *
 *       Filename:  2371.cpp
 *
 *    Description:  solution to zoj 2371
 *
 *        Version:  1.0
 *        Created:  2007年05月04日 00时11分58秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<bitset>
#include<algorithm>
#include<cstdio>
#include<vector>
#define LEN 68
void mutipl3(const std::string& first, std::string& second )
{
	int temp,carry;	
	carry = 0;
	for( size_t i = 0; i < first.size(); i++ )
	{
		temp = (first[i]-'0')*3+carry;
		carry = temp/10;
		temp = temp%10;
		second.push_back(temp+'0');
	}
	if( carry != 0 )
		second.push_back(carry+'0');
}
inline void set_power3( std::vector<std::string>&power3 )
{
	power3[0] = "1";
	for( int i = 1; i < LEN; i++ )	
		mutipl3(power3[i-1],power3[i]);
}
inline void set_mask(std::vector<unsigned long long>&mask)
{
	mask[0] = 1;
	for( int i = 1; i < LEN; i++ )
		mask[i] = mask[i-1]*2;
}

int main()
{
	int count = 0;
	unsigned long long idx;
	std::vector<std::string>power3(LEN);
	std::vector<unsigned long long>mask(LEN);
	set_power3(power3);
	set_mask(mask);
	while( std::scanf("%lld",&idx) && idx != 0 )
	{
		count = 0;
		std::printf("{");
		for( int i = 0; i < LEN; i++ )
		{
			if( mask[i]&(idx-1) )
			{
				if( count++ )
					std::printf(",");
				std::string temp = power3[i];
				reverse(temp.begin(),temp.end());
				std::printf(" %s",temp.c_str());
			}
		}
		std::printf(" }\n");	
	}
	return 0;
}


