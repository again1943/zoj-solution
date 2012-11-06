#include<cstdio>
#include<algorithm>
using namespace std;

struct character_t
{
	char name[32];
	int armor,hp,power,amount,cool,damage;
}ch[2];

int main()
{
	int t0,t1;
	while( scanf("%s",ch[0].name) != -1 )	
	{
		scanf("%d%d%d%d%d",&ch[0].hp,
			&ch[0].armor,&ch[0].cool,&ch[0].amount,&ch[0].power);	
		scanf("%s",ch[1].name);
		scanf("%d%d%d%d%d",&ch[1].hp,
			&ch[1].armor,&ch[1].cool,&ch[1].amount,&ch[1].power);	

		ch[0].damage = max(1,(ch[0].power-ch[1].armor)*ch[0].amount);
		ch[1].damage = max(1,(ch[1].power-ch[0].armor)*ch[1].amount);
		t0 = ch[0].hp/ch[1].damage;
		t1 = ch[1].hp/ch[0].damage;
		if( ch[0].hp % ch[1].damage != 0 )
			t0 += 1;
		if( ch[1].hp % ch[0].damage != 0 )
			t1 += 1;
		t0 *= ch[1].cool;
		t1 *= ch[0].cool;
		if( t0 == t1 ) 
			printf("All Die!\n");
		else
			printf("%s Survive!\n",t0<t1?ch[1].name:ch[0].name);
	}
	return 0;
}
