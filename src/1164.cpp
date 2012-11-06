#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;
#define LINE_SIZE 1024

char map[] = "0123456789ABCDEF";
char line[LINE_SIZE];

unsigned short int do_crc( const char* line, unsigned short int Y )
{
	unsigned int sum = 0;	

	for( int i = 0; line[i] != 0; i++ )
		sum = (sum*256+line[i])%Y;
	return Y-(sum<<16)%Y;
}
int main()
{
	unsigned short int CRC;
	unsigned short int Y = 34943;	
	while( gets(line) && strcmp(line,"#") != 0 )
	{
		if( line[0] == 0 )
			CRC=0;
		else
			CRC = do_crc(line,Y);
		printf("%c%c %c%c\n",map[(CRC&0xf000)>>12],
		map[(CRC&0x0f00)>>8],map[(CRC&0x00f0)>>4],map[CRC&0x000f]);
	}
	return 0;
}
