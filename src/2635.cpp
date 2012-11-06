#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
using namespace std;

#define KEY_SIZE 26
#define TEXT_SIZE 100

char key[KEY_SIZE];
char plain_text[TEXT_SIZE];
char cipher_text[TEXT_SIZE];
char transform_table[KEY_SIZE][KEY_SIZE];

void cipher_decode(char* key,char* cipher_text)
{
	char c;
	int idx,i,j;
	int cipher_pos,plain_pos;
	char copy_key[KEY_SIZE];	
	int key_len = strlen(key);
	int cipher_len = strlen(cipher_text);
	int last = cipher_len%key_len;
	int table_size = cipher_len/key_len+1;

	strcpy(copy_key,key);
	sort(copy_key,copy_key+key_len);

	for( i = 0,cipher_pos = 0; i < key_len; i++ )
	{
		c = copy_key[i];	
		idx = find(key,key+key_len,c)-key;
		for( j = 0; j < table_size-1; j++ )	
			transform_table[j][idx] = cipher_text[cipher_pos++];
		if( idx < last )
			transform_table[table_size-1][idx] = cipher_text[cipher_pos++];
	}
	plain_pos = 0;
	for( i = 0; i < table_size-1; i++ )
	for( j = 0; j < key_len; j++ )
		plain_text[plain_pos++] = transform_table[i][j]-'A'+'a';
	for( j = 0; j < last; j++ )
		plain_text[plain_pos++] = transform_table[table_size-1][j]-'A'+'a';
	plain_text[plain_pos] = '\0';

}

int main()
{
	int n;
	scanf("%d",&n);
	for( int i = 0; i < n; i++ )
	{
		scanf("%s%s",key,cipher_text);
		cipher_decode(key,cipher_text);
		printf("%s\n",plain_text);
	}
	return 0;
}
