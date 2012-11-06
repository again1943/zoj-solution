#include<cstdio>

using namespace std;

int main()
{
	char name[16][26];
	int set = 0;
	int num;
	int tag;
	scanf("%d",&num);
	while( num != 0 )
	{
		for(  tag = 0; tag < num; tag++ )
			scanf("%s",name[tag]);
		printf("SET %d\n",++set);
		for( tag = 0; tag*2 < num; tag++ )
			printf("%s\n",name[2*tag]);
		tag--;
		tag = ( 2*tag + 1  <  num ) ?( 2*tag+1):(2*tag-1);
		for(  ; tag >= 0; tag -= 2 )
			printf("%s\n",name[tag]);
		scanf("%d",&num);
		tag = 0;
	}
	return 0;
}
