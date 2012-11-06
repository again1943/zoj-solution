#include<cstdio>
#include<algorithm>
using namespace std;
#define MEMORY_SIZE 256
#define HALT_INST 8
char memory[MEMORY_SIZE];
char transform( char c )
{
	if( c >= '0' && c <= '9' )
		return c-'0';
	else
		return c-'A'+10;
}

inline char decode_instruction(char* memory,int pc, unsigned char& arg )
{
	arg = transform(memory[pc+1])*16+transform(memory[pc+2]);
	return memory[pc]-'0';
}

char reverse_transform( char c )
{
	if( c >= 0 && c <= 9 )
		return c+'0';
	else
		return c-10+'A';
}
void excute_programe(char* memory)
{
	unsigned char arg;
	char A,B,C,pc,opcode;

	A = B = pc = 0;
	while( (opcode = decode_instruction(memory,pc,arg)) != HALT_INST)
	{
		switch( opcode )
		{
			case 0:
				A = transform(memory[arg]);
				pc += 3;
				break;
			case 1:
				memory[arg] = reverse_transform(A);
				pc += 3;
				break;
			case 2:
				swap(A,B);	
				pc += 1;
				break;
			case 3:
				C = A+B;
				A = C&0x0f;
				B = (C&0xf0) >> 4;
				pc += 1;
				break;
			case 4:
				A = (A+1)%16;
				pc += 1;
				break;
			case 5:
				A = ( A == 0 ) ? 15:A-1;
				pc += 1;
				break;
			case 6:
				pc = (A == 0)?arg:pc+3;	
				break;
			case 7:
				pc = arg;
				break;
			default:
				break;
		}
	}
}
int main()
{
	while(scanf("%s",memory) && memory[0] != '8')	
	{
		excute_programe(memory);
		printf("%s\n",memory);
	}
}
