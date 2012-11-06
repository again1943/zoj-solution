/*
 * =====================================================================================
 *
 *       Filename:  1243.cpp
 *
 *    Description:  solution to zoj 1243
 *
 *        Version:  1.0
 *        Created:  2007年11月02日 14时37分40秒 CST
 *       Revision:  none
 *       Compiler:  gcc/g++
 *
 *         Author:  Fatrat from Mars 
 *        Company:  
 *
 * =====================================================================================
 */
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

void get_all(string& line,string& protocol,string& host,string& port,string& path)
{
        size_t pos,next;
        pos = line.find("://");
        protocol = line.substr(0,pos);
        pos += 3;

        if( (next = line.find(':',pos)) == string::npos 
                        || line[next+1] < '0' || line[next+1] > '9')
        {
                port = "<default>";
                if( (next = line.find('/',pos)) == string::npos )
                {
                        path = "<default>";
                        host = line.substr(pos,line.size()-pos);
                }
                else
                {
                        path = line.substr(next+1,line.size()-next-1);
                        host = line.substr(pos,next-pos);
                }
        }
        else
        {
                host = line.substr(pos,next-pos);
                next++;
                path = line.substr(pos,next-pos);
                while(  line[next] >= '0' && line[next] <= '9' )
                        port.push_back(line[next++]);
		if( next == line.size() )
			path = "<default>";
		else
			path = line.substr(next+1,line.size()-next-1);
        }
}
int main()
{
        int n;
        string line,protocol,host,port,path;
        cin >> n;
        for(int i = 0; i < n; i++ )
        {
                cin >>  line;
                get_all(line,protocol,host,port,path);
                cout << "URL #" << i+1 << '\n';
                cout << "Protocol = " << protocol << '\n'; 
                cout << "Host     = " << host << '\n';
                cout << "Port     = " << port << '\n';
                cout << "Path     = " << path << '\n' << endl;;
                protocol.clear();
                host.clear();
                port.clear();
                path.clear();
        }
        return 0;
}

