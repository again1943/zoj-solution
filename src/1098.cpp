#include<cstdio>
#include<cstdlib>
using namespace std;

#define MEM_SIZE 32
#define STA 0x00
#define LDA 0x20
#define BEQ 0x40
#define NOP 0x50
#define DEC 0x80
#define INC 0xa0
#define JMP 0xc0
#define HLT 0xe0

unsigned char memory[MEM_SIZE];

unsigned char mask[8] = 
{
	0x1,0x2,0x4,0x8,0x10,0x20,0x40,0x80
};

unsigned char get_binary( char* line )
{
	unsigned char ret = 0;			
	for( int i = 7; i >= 0; i-- )
		if( line[i] == '1' )
			ret |= mask[7-i];
	return ret;
}

char* get_char( char* str, unsigned char ret )
{
	for( int i = 7; i >= 0; i-- )
		str[7-i] = ((ret&mask[i])>>i)+'0';
	return str;
}

unsigned char start_programe()
{
	unsigned char current;
	unsigned char pc = 0;
	unsigned char accu = 0;
	unsigned char ins_mask = 0xe0;
	unsigned char arg_mask = 0x1f;
	unsigned char arg,ins;
	while((ins = ((current = memory[pc])&ins_mask)) != HLT)
	{
		
		pc = (pc+1)%32;

		switch( ins )
		{
			case STA:
				arg = current&arg_mask;
				memory[arg] = accu;
				break;
			case LDA:
				arg = current&arg_mask;
				accu = memory[arg];
				break;
			case BEQ:
				if( accu == 0 )
					pc = current&arg_mask;
				break;
			case DEC:
				accu--;
				break;
			case INC:
				accu++;
				break;
			case JMP:
				pc = current&arg_mask;
				break;
			default:
				break;
		}
	}
	return accu;
}
int main()
{
	unsigned char ret;
	char line[9];
	while( scanf("%s",line) != -1 )
	{
		memory[0] = get_binary(line);
		for( int i = 1; i < 32; i++ )
		{
			scanf("%s",line);
			memory[i] = get_binary(line);
		}
		ret = start_programe();
		printf("%s\n",get_char(line,ret));
	}
	return 0;
}

