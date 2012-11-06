#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MORSE_CODE_LEN 6
#define MESSAGE_LEN 100

const char morse_code[][MORSE_CODE_LEN] =
{
	/*ABCDEFG*/".-","-...","-.-.","-..",".","..-.","--.",
	/*HIJKLMN*/"....","..",".---","-.-",".-..","--","-.",
	/*OPQRSTU*/"---",".--.","--.-",".-.","...","-","..-",
	/*VWXYZ*/"...-",".--","-..-","-.--","--..",
//	/*_,.?*/"..--",".-.-","---.","----"
};
int morse_len[] = 
{
	/*ABCDEFG*/2,4,4,3,1,4,3,
	/*HIJKLMN*/4,2,4,3,4,2,2,
	/*OPQRSTU*/3,4,4,3,3,1,3,
	/*VWXYZ*/4,3,4,4,4
};
char message[MESSAGE_LEN];
char mess_morse[MESSAGE_LEN*5];
int mess_seq[MESSAGE_LEN];

int deal_message()
{
	int i;
	int idx = 0;
	for( i = 0; message[i] != '\0'; i++ )
	{
		switch(message[i])	
		{
			case '_':
				strcpy(mess_morse+idx,"..--");
				idx += 4;
				mess_seq[i] = 4;
				break;
			case '.':
				strcpy(mess_morse+idx,"---.");
				idx += 4;
				mess_seq[i] = 4;
				break;
			case ',':
				strcpy(mess_morse+idx,".-.-");
				idx += 4;
				mess_seq[i] = 4;
				break;
			case '?':
				strcpy(mess_morse+idx,"----");
				idx += 4;
				mess_seq[i] = 4; 
				break;
			default:
				strcpy(mess_morse+idx,morse_code[message[i]-'A']);
				idx+= (mess_seq[i] = morse_len[message[i]-'A']);
				break;
		}
	}
	return i;
}

char look_up( char* morse )
{
	if( strcmp(morse,"..--" ) == 0 )	
		return '_';
	if( strcmp(morse,".-.-" ) == 0 )
		return ',';
	if( strcmp(morse,"---." ) == 0 )
		return '.';
	if( strcmp(morse,"----" ) == 0 )
		return '?';
	for( int i = 0; i < 26; i++ )
		if( strcmp(morse,morse_code[i]) == 0 )	
			return 'A'+i;
	return '\0';
}
int main()
{
	int n,len,pos,i,j;	
	char word[MORSE_CODE_LEN];
	scanf("%d",&n);
	for( i = 0; i < n; i++ )
	{
		scanf("%s",message);
		len = deal_message();
		for(j = pos = 0; j < len; j++ )
		{
			memcpy(word,mess_morse+pos,mess_seq[len-j-1]);	
			word[mess_seq[len-j-1]] = '\0';
			pos += mess_seq[len-j-1];
			message[j] = look_up(word);
		}
		message[len] = '\0';
		printf("%d: %s\n",i+1,message);
	}
	return 0;
}
