#include<iostream>
using namespace std;
#define NUM_CNT 70001
unsigned short int bit_stream[NUM_CNT];

int get_one( unsigned short int* bit, int offset )
{
	int ret,tmp;
	int idx = offset/16;
	int pos = offset%16;
	if( pos + 7 < 16 )
		tmp = (bit[idx]>>(9-pos))&0x7f;
	else
		tmp = (((bit[idx]<<(16-pos)) >> ( 16-pos ))<<(pos-9))+(bit[idx+1]>>(25-pos));
	ret = (tmp&0x3f);
	if( (tmp&0x40) != 0 )
		ret  = -ret;
	return ret;
}

int main()
{
	int n,i,sum,cnt;
	while( cin >> n && n != -1 )
	{
		for( i = 0; i < n; i++ )
			cin >> bit_stream[i];
		cnt = 16*n/7;
		for( i = sum = 0; i < cnt; i++ )
			sum += get_one(bit_stream,i*7);
		cout << sum << endl;
	}
	return 0;
}
