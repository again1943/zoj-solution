#include<cstdio>
#include<algorithm>
#define MAX 1000
using namespace std;
class FatMouse
{
private:	
	int TestCase;
	double TotalFood;
	struct Pair
	{
		double JavaBean;
		double Food;
	}Trade[MAX];
	class SortPolicy
	{
	public:	
		bool operator()(const Pair& First, const Pair& Second)
		{
			return  First.JavaBean/First.Food >= Second.JavaBean/Second.Food;
		}
	};
public:
	bool Read();
	double Deal();
};

bool FatMouse::Read()
{
	scanf("%lf%d",&TotalFood,&TestCase);	
	if( TotalFood == -1 && TestCase == -1 )
		return false;
	else
	{
		for( int i = 0; i < TestCase; i++ )
			scanf("%lf%lf",&Trade[i].JavaBean,&Trade[i].Food);
		return true;
	}
}

double FatMouse::Deal()
{
	double GetJavaBean = 0.0;
	stable_sort(Trade,Trade+TestCase,SortPolicy() );
	
	for( int i = 0; i < TestCase && TotalFood > 0; i++ )
	{
		if( TotalFood >= Trade[i].Food )
		{
			GetJavaBean += Trade[i].JavaBean;
			TotalFood -= Trade[i].Food;
		}
		else
		{
			GetJavaBean += (TotalFood/Trade[i].Food)*Trade[i].JavaBean;
			TotalFood = 0;
			break;
		}
	}
	return GetJavaBean;

}

int main()
{
	FatMouse FM;
	while( FM.Read() != false )
		printf("%0.3lf\n",FM.Deal());
	return 0;
}
