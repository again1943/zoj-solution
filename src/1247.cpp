/*
 * =====================================================================================
 *
 *       Filename:  1247.cpp
 *
 *    Description:  solution to zoj 1247
 *
 *        Version:  1.0
 *        Created:  2007年10月22日 14时31分20秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars
 *        Company:  Mars
 *
 * =====================================================================================
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

#define ZERO 1e-8
#define SIZE 251
double SQRT_2;
char line[SIZE];

int decode( char* code )
{
        switch( code[0] )
        {
                case 'E':
                        return 0;
                case 'N':
                        if( code[1] == 'E' )
                                return 1;
                        if( code[1] == 'W')
                                return 3;
                        else
                                return 2;
                case 'W':
                        return 4;
                case 'S':
                        if( code[1] == 'W' )
                                return 5;
                        if( code[1] == 'E' )
                                return 7;
                        else
                                return 6;
                default:
                        return -1;
        }

}
char* get_step(char* line, int* step )
{
        char num[10];
        char *p = num;
        while(*line >= '0' && *line <= '9')
                *p++ = *line++;
        *p = '\0';
        *step = atoi(num);
        return line;
}
char* get_code(char* line, int* code )
{
        char dir[10];
        char*p = dir;
        while(*line == 'S' || *line == 'E'
                || *line == 'W' || *line == 'N' )
                *p++ = *line++;
        *p = '\0';
        *code = decode(dir);
        return ++line;
}

void analyze(char* line, double* x,double* y)
{
        char* p = line;

        int step;
        int code;
        double temp;
        *x = *y = 0.0000000;

        while( *p != '\0')
        {
                p = get_step(p,&step);
                p = get_code(p,&code);
                temp = step/SQRT_2;
                switch( code )
                {
                        case 0:
                                *x += step;
                                break;
                        case 1:
                                *x += temp;
                                *y += temp;
                                break;
                        case 2:
                                *y += step;
                                break;
                        case 3:
                                *x -= temp;
                                *y += temp;
                                break;
                        case 4:
                                *x -= step;
                                break;
                        case 5:
                                *x -= temp;
                                *y -= temp;
                                break;
                        case 6:
                                *y -= step;
                                break;
                        case 7:
                                *x += temp;
                                *y -= temp;
                        default:
                                break;
                }
        }
}
int main()
{
        int n = 0;
        double x,y;
        SQRT_2 = sqrt(2.0);
        while( scanf("%s",line) && strcmp(line,"END") != 0 )
        {
                analyze(line,&x,&y);
                printf("Map #%d\n",++n);
		if( abs(x) < ZERO )
			x = 0.0000;
		if( abs(y) < ZERO )
			y = 0.0000;
                printf("The treasure is located at (%0.3lf,%0.3lf).\n",x,y);
                printf("The distance to the treasure is %0.3lf.\n\n",sqrt(x*x+y*y));
        }
        return 0;
}

