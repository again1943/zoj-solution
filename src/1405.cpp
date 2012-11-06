#include<cstdio>
#include<cstring>
using namespace std;
#define TANNINT_LETTER 26
#define LINE_LEN 64
char line[LINE_LEN];
bool present[TANNINT_LETTER];
bool appear[TANNINT_LETTER];

int main()
{
	int n,i;
	int current,leave;
	while( scanf("%d",&n) && n != 0 )
	{
		scanf("%s",line);	
		memset(present,0,sizeof(present));			
		memset(appear,0,sizeof(appear));
		for( current = leave = i = 0; line[i] != 0; i++ )		
		{
			if( current == n && present[line[i]-'A'] == false)
			{
				if ( appear[line[i]-'A'] == true )
					leave += 1;
				appear[line[i]-'A'] = !appear[line[i]-'A'];
			
			}
			else
			{
				if( present[line[i]-'A'] == true )	
				{
					current -= 1;
					present[line[i]-'A'] = false;
				}
				else
				{
					present[line[i]-'A'] = true;	
					current += 1;
				}
			}
		}
		if( leave == 0 )
			printf("All customers tanned successfully.\n");	
		else
			printf("%d customer(s) walked away.\n",leave);
	}
	return 0;
}
