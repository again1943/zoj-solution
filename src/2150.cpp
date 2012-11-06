/*
 * =====================================================================================
 *
 *       Filename:  2150.cpp
 *
 *    Description:  solution to zoj 2150
 *
 *        Version:  1.0
 *        Created:  2007年04月28日 01时17分26秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Fatrat
 *
 * =====================================================================================
 */

#include<cstdio>
#include<cstdlib>
#include<utility>
#include<cmath>

long long recursive_do_single( std::pair<long long,long long>data,long long m)
{
	long long n,s,t;	
	std::lldiv_t temp;

			
	t = data.first;	
	//data.first == 0,return 0
	//data.first == 1,return 1
	//data.second == 0,return 1
	//data.second == 1,return data.first%m
	if( data.first < 2 )
		return data.first;
	if( data.second == 0 )
		return 1;
	if( data.second == 1 )
		return data.first%m;

	//then else both data.first >=2 and data.second >= 2
	n = static_cast<long long>(log(m)/log(data.first))+1;		

	if( n >= data.second )
	{
		for( int i = 1; i < data.second; i++ )	
			data.first *= t;
		return data.first%m;
	}


	else
	{
		for( int i = 1; i < n; i++ )
			data.first *= t;
		data.first %= m;
		temp = std::lldiv(data.second,n);
		data.second = temp.quot;

		s = 1;
		for( int i = 0; i < temp.rem; i++ )
			s *= t;
		return (s*recursive_do_single(data,m))%m;
	}
}
int main()
{
	long long m,n,sum;
	long long test_case;	
	std::pair<long long,long long>data;

	std::scanf("%lld",&test_case);

	for( int i = 0; i < test_case; i++ )
	{
		std::scanf("%lld%lld",&m,&n);
		sum = 0;
		for( int i = 0; i < n; i++ )
		{
			std::scanf("%lld%lld",&data.first,&data.second);
			if( m != 1 )
			{
				data.first %= m;
				if( data.first > 1 )
					sum += recursive_do_single(data,m);
				else
					sum += data.first;
					
			}
		}
		std::printf("%lld\n",sum%m);
	}
	return 0;
}
