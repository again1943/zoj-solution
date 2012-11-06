#include <cstdio>
#include <cstdlib>
#include <string>
#include <algorithm>

using namespace std;
#define MAX_SQ 36000
#define MAX_SN 2147483647

long fn[MAX_SQ];
long long sn[MAX_SQ];
string maxfn;

int LENGTH(int n)
{
	char word[32];
	int len = 0;
	while( n != 0 )
	{
		word[len++] = n%10+'0';
		n /= 10;
	}
	word[len] = 0;
	reverse(word,word+len);
	maxfn += string(word);
	return len;
}
int calc_before()
{
	int j;
	int i = 2;
	sn[1] = fn[1] = 1;
	maxfn = "01";
	while(sn[i-1] < MAX_SN )
	{
		fn[i] = fn[i-1]+LENGTH(i);
		sn[i] = sn[i-1]+fn[i];
		i += 1;
	}
	return i;
}

char seq(int n, int s)
{
	long long *p;
	long long next = n;
	//static int first10 = {-1}
	p  = lower_bound(sn+1,sn+s,(long long)next);
	next = next-*(p-1);
	return maxfn[next];
}

int main()
{
	int n,i,m,s;
	s = calc_before();
	scanf("%d",&m);
	for( i = 0; i < m; i++ )
	{
		scanf("%d",&n);
		printf("%c\n",seq(n,s));
	}
	return 0;
}