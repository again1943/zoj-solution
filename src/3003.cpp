#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

#define MAX_NODE 1024
#define MAX_VTIME 1200

std::map<std::string,int> name2id;

//short tcost[MAX_VTIME];
short cost[MAX_NODE];
short child_count[MAX_NODE];
short child[MAX_NODE][MAX_NODE];
std::vector<std::pair<short,double> > values[MAX_NODE];

inline void insert(std::vector<std::pair<short,double> >* middle, short* range, short r, const std::pair<short,double>& p)
{
    short& m = range[p.first];
    if (m < 0) {
        middle[1].push_back(p);
        m = static_cast<short>(middle[1].size()-1);
    } else {
        middle[1][m].second = std::min(p.second,middle[1][m].second);
    }
}

void dfs(short n, short v, short r)
{
    short range[MAX_VTIME];
    std::vector<std::pair<short,double> >middle[2];

    if (child_count[r] == 0) {
        values[r].push_back(std::make_pair(1,cost[r]*1.0/v));
        return;
    }
    memset(range,-1,sizeof(short)*MAX_VTIME);
    for (short x = 0; x < child_count[r]; ++x) {
        short tmp,tmp2;
        short c = child[r][x];
        dfs(n,v,c);
        for (size_t ip = 0; ip < values[c].size(); ++ip) {
            std::pair<short,double>& m1 = values[c][ip];
            for (size_t it = 0; it < middle[0].size(); ++it) {
                std::pair<short,double>& m2 = middle[0][it];
                insert(middle,range,r,std::make_pair(m1.first+m2.first,m1.second+m2.second));
            }
            insert(middle,range,r,m1);
        }
        middle[0] = middle[1];
    }
    for (size_t it = 0; it < middle[0].size(); ++it) {
        std::pair<short,double>& m = middle[0][it];
        m.second += cost[r]*1.0/(m.first+v);
        m.first += 1;
        values[r].push_back(m);
    }
}

double search(short n, short v, short a)
{
    double tcost = 1e10;
    dfs(n,v,a);
    for (size_t it = 0; it < values[a].size(); ++it) {
        std::pair<short,double>& m = values[a][it];
        tcost = std::min(m.second,tcost);
    }
    return tcost;
}

int main()
{
    std::string name,name2;
    short n,v,t,c,a,b;
    while (std::cin >> n >> v) {
        t = 0;
        for (int x = 0; x < n; ++x) {
            std::cin >> name >> c;
            name2id.insert(std::make_pair(name,t));
            cost[t++] = c;
        }
        memset(child_count,0,sizeof(child_count));
        for (int x = 0; x < n-1; ++x) {
            std::cin >> name >> name2;
            a = name2id[name];
            b = name2id[name2];
            short& r = child_count[b];
            child[b][r++] = a;
        }
        std::cin >> name;
        a = name2id[name];
        printf("%0.2lf\n",search(n,v,a));
        for (size_t it = 0; it < t; ++it) {
            values[it].clear();
        }
        name2id.clear();
    }
    return 0;
}

