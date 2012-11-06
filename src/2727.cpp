#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct book_list
{
	char name[80];
	int year;
	int price;
};
char criteria[10];
struct op
{	
	bool operator()( const book_list& first,const book_list& second );
};
bool op::operator()( const book_list& first,const book_list& second )
{
	int  order_1 = strcmp( first.name,second.name ); 
	int  order_2 = first.year - second.year ;
	int  order_3 = first.price - second.price ;
	if( strcmp( criteria,"Year" ) == 0 )
		return ( order_2 < 0 ) ||
			( order_2 == 0 && order_1 < 0 )||
			( order_2 == 0 && order_1 == 0 && order_3 < 0 ); 
	else if( strcmp( criteria,"Price" ) == 0 )
		return ( order_3 < 0 )||
			( order_3 == 0 && order_1 < 0 )||
			(order_3 == 0 && order_1 == 0 && order_2 < 0 );
	else
		return ( order_1 < 0 )||
			( order_1 == 0 && order_2 < 0 ) ||
			( order_1 == 0 && order_2 == 0 && order_3 < 0);
}

int main()
{
	book_list book[100];
	int num;
	int time = 0;
	scanf("%d",&num);
	while( num != 0 )
	{
		time++;
		for( int i = 0;i<num;i++ )
			scanf("%s%d%d",book[i].name,&book[i].year,&book[i].price);
		scanf("%s",criteria);
		stable_sort(book,book+num,op());
		if( time > 1 )
			printf("\n");
		for( int i = 0; i < num;i++ )
			printf("%s %d %d\n",book[i].name,book[i].year,book[i].price );
		scanf("%d",&num);
	}
	return 0;
}
