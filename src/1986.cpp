/*
 * =====================================================================================
 *
 *       Filename:  1986.cpp
 *
 *    Description:  solution to zoj 1986
 *
 *        Version:  1.0
 *        Created:  2007年10月25日 15时10分58秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */

#include<algorithm>
#include<limits>
#include<vector>
#include<utility>

using namespace std;
#define SIZE 40000

template<typename RandomAccessIterator>
size_t lis(RandomAccessIterator first,
	RandomAccessIterator last/*RandomAccessIterator output*/ )
{
	int p,r,m;
	int curren_len = 1;
	RandomAccessIterator iter;
	typename std::iterator_traits<RandomAccessIterator>::difference_type 
		len = std::distance(first,last);
	std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type>
		record(len+1);
	record[0] = std::numeric_limits<
		typename std::iterator_traits
		<RandomAccessIterator>::value_type>::min();
	record[1] = *first;
	for( iter = first+1; iter != last; ++iter )
	{
		p = 0;	
		r = curren_len;
		while( p <= r )
		{
			m = (p+r)/2;	
			if( record[m] < *iter )
				p = m+1;
			else
				r = m-1;
		}
		record[p] = *iter;
		if( p > curren_len )
			curren_len++;
	}
	return curren_len;
	//return std::copy(record.begin()+1,record.begin()+curren_len+1,output);
}

int signal_map[SIZE];

int main()
{
	int n,r;
	scanf("%d",&n);
	for( int i = 0; i < n; i++ )
	{
		scanf("%d",&r);
		for( int j = 0; j < r; j++ )
			scanf("%d",&signal_map[j]);
		printf("%d\n",lis(signal_map,signal_map+r));
	}
	return 0;
}
