/*
 * =====================================================================================
 *
 *       Filename:  1745.cpp
 *
 *    Description:  solution to zoj 1745
 *
 *        Version:  1.0
 *        Created:  2007年05月18日 11时16分49秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int target;	
	int last,current;
	int t = 0;
	while( scanf("%d",&target)&& target < 5280 )
	{
		last = 0;		
		if( t++ )
			printf("\n");
		while( scanf("%d",&current) && current != target )
		{
			if( abs(last-target) > abs(current-target))
				printf("Moving from %d to %d: warmer.\n",last,current);
			else if(abs(last-target) < abs(current-target))
				printf("Moving from %d to %d: colder.\n",last,current);
			else	
				printf("Moving from %d to %d: same.\n",last,current);
			last = current;
		}
		printf("Moving from %d to %d: found it!\n",last,current);
	}
	return 0;
}

