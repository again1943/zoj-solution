#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define DIGIT_LEN 1024
char result[DIGIT_LEN*2];
char line[DIGIT_LEN];
int store( char* result, int idx, char digit,int count )
{
	int start = idx;
	while( count != 0 )
	{
		result[idx++] = count%10+'0';	
		count /= 10;
	}
	reverse(result+start,result+idx);
	result[idx++] = digit;
	return idx;
}
void parse( char* line )
{
	int i,idx;		
	char digit = line[0];
	int count = 1;
	for( i = 1,idx = 0; line[i] != 0; i++ )
	{
		if( digit == line[i] )	
			count += 1;
		else
		{
			idx = store(result,idx,digit,count);		
			count = 1;
			digit = line[i];
		}
	}
	idx = store(result,idx,digit,count);
	result[idx] = 0;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%s",line);
		parse(line);
		printf("%s\n",result);
	}
	return 0;
}
