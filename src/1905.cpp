#include<string>
#include<iterator>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;

bool do_test( string& line, int  step )
{
        int i;
        int iter = line.size()/step;
        string::iterator start = line.begin();
        for( i = 2; i <= iter; i ++ )
        {
	#ifdef DEBUG
		cout << "At this iteration:" << endl;
		copy(start,start+step,ostream_iterator<char>(cout," "));
		cout << endl;
		copy(start+(i-1)*step,start+i*step,ostream_iterator<char>(cout," "));
		cout << endl;
	#endif
                if( equal(start,start+step,start+(i-1)*step) != true )
			return false;
        }
	return true;
}
int main()
{
        int len;
        bool flag;
        string line;
        while( ( cin >> line )&& line != "." )
        {
                len = line.size();
                flag = false;
                for( int i = 1; i < len; i++ )
                {
                        if( len% i == 0 && do_test(line,i) == true )
                        {
                                cout << len/i << endl;
                                flag = true;
                                break;
                        }
                }
                if( flag == false )
                        cout << 1 << endl;
        }
        return 0;
}
