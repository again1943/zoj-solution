#include<queue>
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
#define BIT_LEN 10000
union data_t
{
	unsigned char segment[4];
	unsigned int  combine;
};
struct qelem
{
	data_t data;	
	int time;
};

inline int convert_back( data_t& d )
{
	return d.segment[0]*1000+d.segment[1]*100+d.segment[2]*10+d.segment[3];
}
int bfs( data_t& source, data_t& target )
{
	int idx,i;
	int timestamp = 0;
	bitset<BIT_LEN>mask;	
	queue<qelem> Q;
	qelem temp,cpy;
	if( source.combine == target.combine )
		return 0;
	temp.data = source;
	temp.time = timestamp;
	mask[convert_back(source)] = true;
	Q.push(temp);
	while( Q.empty() != true )
	{
		temp = Q.front();
		Q.pop();
		if( temp.data.combine == target.combine )
			return temp.time;
		if( temp.time != timestamp )
			timestamp = temp.time;
		for( i = 0; i < 4; i++ )		
		{
			cpy = temp;
			cpy.data.segment[i] += 1;
			if( cpy.data.segment[i] > 9 )
				cpy.data.segment[i] = 1;
			idx = convert_back(cpy.data);
			if( mask[idx] == false )
			{
				cpy.time = timestamp + 1;				
				Q.push(cpy);
				mask[idx] = true;
			}
		}
		for( i = 0; i < 4; i++ )		
		{
			cpy = temp;
			cpy.data.segment[i] -= 1;
			if( cpy.data.segment[i] < 1 )
				cpy.data.segment[i] = 9;
			idx = convert_back(cpy.data);
			if( mask[idx] == false )
			{
				cpy.time = timestamp + 1;				
				Q.push(cpy);
				mask[idx] = true;
			}
		}
		for( i = 0; i < 3; i++ )
		{
			cpy = temp;
			swap(cpy.data.segment[i],cpy.data.segment[i+1]);
			idx = convert_back(cpy.data);	
			if( mask[idx] == false )
			{
				cpy.time = timestamp+1;
				Q.push(cpy);
				mask[idx] = true;
			}
		}
	
	}
	return -1;
}

void convert_data( int n, data_t& s )
{
	int i;
	int large = 1000;	
	for( i = 0; i < 4; i++ )
	{
		s.segment[i] = n/large;
		n %= large;	
		large /= 10;
	}
}
int main()
{
	int n,i;
	data_t s,t;
	int source,target;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%d%d",&source,&target);
		convert_data(source,s);
		convert_data(target,t);
		printf("%d\n",bfs(s,t));	
	}
	return 0;
}
