#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

#define MESSAGE_LEN 30
#define PASS_LEN 30

char servants[PASS_LEN];
char message[MESSAGE_LEN];

void reverse_j(char* message)
{
	int len = strlen(message);
	char last = message[len-1];
	for( int i = len-1; i > 0; i-- )
		message[i] = message[i-1];
	message[0] = last;
}
void reverse_c(char* message)
{
	int i;
	char first = message[0];
	for( i = 0; message[i+1] != '\0'; i++ )
		message[i] = message[i+1];
	message[i] = first;
}
void reverse_e(char* message)
{
	int len = strlen(message);	
	int half_len = len/2;
	if( len % 2 == 0 )
	{
		for( int i = 0; i < half_len; i++ )
			swap(message[i],message[half_len+i]);
	}
	else
	{
		for( int i = 0; i < half_len; i++ )
			swap(message[i],message[half_len+i+1]);
	}
}
void reverse_a(char* message)
{
	int len = strlen(message);
	for( int i = 0,j = len-1; i < j; i++,j-- )
		swap(message[i],message[j]);
}
void reverse_p(char* message)
{
	int len = strlen(message);
	for( int i = 0; i < len; i++ )
		if( message[i] >= '0' && message[i] <= '9' )
			message[i] = (message[i]-1 >= '0')? 
						message[i]-1:'9';
}
void reverse_m(char* message)
{
	int len = strlen(message);
	for( int i = 0; i < len; i++ )
		if( message[i] >= '0' && message[i] <= '9' )
			message[i] = (message[i]+1 <= '9')? message[i]+1:'0';

}
int main()
{
	int n;
	int len;
	scanf("%d",&n);
	for( int i = 0; i < n; i++ )
	{
		scanf("%s%s",servants,message);	
		for( len = strlen(servants)-1; len >= 0; len-- )
		{
			switch(servants[len])
			{
				case 'J':
					reverse_j(message);
					break;
				case 'C':
					reverse_c(message);
					break;
				case 'E':
					reverse_e(message);
					break;
				case 'A':
					reverse_a(message);
					break;
				case 'P':
					reverse_p(message);
					break;
				case 'M':
					reverse_m(message);
				default:
					break;
			}
		}
		printf("%s\n",message);
	}
	return 0;
}
