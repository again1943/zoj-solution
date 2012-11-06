/*
 * =====================================================================================
 *
 *       Filename:  1222.cpp
 *
 *    Description:  solution to zoj 1222
 *
 *        Version:  1.0
 *        Created:  2007年10月21日 16时02分58秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
using namespace std;
#define SIZE 10000

int ws[SIZE];
void start()
{
        int current,product;

        product = 1;
        ws[0] = ws[1] = 1;

        for( int i = 2; i < SIZE; i++ )
        {
                current = i;
                while( current % 5 == 0 )
                {
                        current /= 5;
                        product >>= 1;
                }
                product = (product%100000)*current;
                ws[i] = product%10;
        }
}
int main()
{
        int n;
        start();
        while( scanf("%d",&n) != -1 )
                printf("%d\n",ws[n]);
        return 0;
}

