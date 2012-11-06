#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct user
{
	char name[15];
	char passwd[15];
};

bool check_passwd( char* passwd )
{
	char* p = passwd;
	bool modify = true;
	while( *p != '\0' )
	{
		switch( *p )
		{
			case '1':
				modify = false;
				*p = '@';
				break;
			case '0':
				*p = '%';
				modify = false;
				break;
			case 'l':
				*p = 'L';
				modify = false;
				break;
			case 'O':
				modify = false;
				*p = 'o';
				break;
			default:
				break;
		}
		p++;
	}

	return modify;
}
user group[1002];

int main()
{
	int num;
	int modify;
	scanf("%d",&num);
	user single;
	while( num != 0 )
	{
		modify = 0;
		for( int i = 0; i < num; i++ )
		{
			scanf("%s%s",single.name,single.passwd);
			if( check_passwd( single.passwd ) == false )
				group[modify++] = single;
		}

		if( modify == 0 )
			printf("No account is modified.\n");
		else
		{
			printf("%d\n",modify);
			for( int i = 0; i < modify; i++ )
				printf("%s %s\n",group[i].name,group[i].passwd);
		}
		scanf("%d",&num);
	}
	return 0;
}
