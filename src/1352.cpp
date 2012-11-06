#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
#define LINE_LEN 512 
char big_num[LINE_LEN];
char out_put[LINE_LEN];
char res_let[LINE_LEN];

inline int get_num( char c )
{
	if( c >= '0' && c <= '9' )
		return c-'0';
	else if( c >= 'A' && c <= 'Z' )
		return c-'A'+10;
	else
		return c-'a'+36;
}
inline char to_char( int num )
{
	if( num >= 0 && num <= 9 )
		return num+'0';
	else if( num >= 10 && num <= 35 )
		return num-10+'A';
	else
		return num-36+'a';
}

void dummy( char* out, int n )
{
	int i;
	for( i = 0; out[i] == '0'; i++ );
	memmove(out,out+i,n-i+1);
}
int divide( char* big_num, char* out, int src_base,int dst_base )
{
	int i,iter;
	for( i = iter = 0; big_num[i] != 0; i++ )
	{
		iter = iter*src_base+get_num(big_num[i]);
		if( iter >= dst_base )
		{
			out[i] = to_char(iter/dst_base);
			iter %= dst_base;
		}
		else
			out[i] = to_char(0);
	}
	out[i] = 0;
	dummy(out,i);
	return iter;
}

int main()
{
	char* x;
	char* y;
	int n,i,idx,src_base,dst_base;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%d%d%s",&src_base,&dst_base,big_num);
		printf("%d %s\n",src_base,big_num);
		idx = 0;
		x = big_num;
		y = out_put;
		while( x[0] != 0 )
		{
			res_let[idx++] = to_char(divide(x,y,src_base,dst_base));
			swap(x,y);
		}
		res_let[idx] = 0;
		reverse(res_let,res_let+idx);
		printf("%d %s\n\n",dst_base,res_let);
	}
	return 0;
}
