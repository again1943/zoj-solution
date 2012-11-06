#include<queue>
#include<string>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define ELEM_CNT 10
#define RES_RANGE 5000

int elem[ELEM_CNT];
bool res[RES_RANGE];

struct queue_elem_t
{
	int r;
	string S;	
};

string do_work( int* e, int n, int m )
{
	int i;
	queue_elem_t item,cpy;
	queue<queue_elem_t>Q;	

	sort(e,e+n);
	memset(res,0,sizeof(res));
	
	for( i = ((e[0] == 0 )?1:0); i < n; i++ )
	{
		item.r = e[i]%m;
		if( res[item.r] == false )	
		{
			item.S = '0'+e[i];
			Q.push(	item);
			res[item.r] = true;
		}
	}
	while( Q.empty() != true )
	{
		item = Q.front();
		Q.pop();
		if( item.r % m == 0 )
			return item.S;	
		else
		{
			for( i = 0; i < n; i++ )
			{
				cpy = item;
				cpy.r = (cpy.r*10+e[i])%m;
				if( res[cpy.r] == false )
				{
					cpy.S.push_back(e[i]+'0');
					Q.push(cpy);
				}
				res[cpy.r] = true;
			}
		}
	}
	return string("0");
}
int main()
{
	int n,mul,i;
	while (cin >> mul >> n)
	{
		for( i = 0; i < n; i++ )
			cin >> elem[i];
		if( mul == 0 )
			cout << 0 << endl;
		else
			cout << do_work(elem,n,mul) << endl;
	}
	return 0;
}
