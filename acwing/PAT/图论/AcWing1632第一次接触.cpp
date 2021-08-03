// PAT甲级真题1139
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int N = 310;
int n,m;
int idx;
unordered_map<string,int> id;
set<int> boys,girls;
string name[N];
bool g[N][N];

int main()
{
    scanf("%d%d", &n, &m);
    char as[N], bs[N];
    while(m--)
    {
        string x,y;
        scanf("%s%s", as, bs);
        x = as, y = bs;
        // cout<<x<<' '<<y<<endl;
        if(id.count(x)==0) id[x]=idx++;
        if(id.count(y)==0) id[y]=idx++;
        int px = id[x], py = id[y];
        if(x.size()==5) girls.insert(px);
        else boys.insert(px);
        if(y.size()==5) girls.insert(py);
        else boys.insert(py);
        
        g[px][py]=true;
        g[py][px]=true;
        name[px]=x;
        name[py]=y;
    }

    int k;
    scanf("%d", &k);
    while(k--)
    {
        string x,y;
        scanf("%s%s", as, bs);
        x = as, y = bs;
        vector<pair<string,string>> res;
        if(id.count(x) && id.count(y))
        {
            auto p = boys, q = boys;
            if (x[0] == '-') p = girls;
            if (y[0] == '-') q = girls;
            int px = id[x], py = id[y];
            
            for(auto& a : p)
            {
                for(auto& b : q)
                {
                    if(px != a && px != b && py != a && py != b && g[px][a] && g[a][b] && g[b][py])
                    {
                        string r1 = name[a],r2 = name[b];
                        if(r1.size()==5) r1 = r1.substr(1);
                        if(r2.size()==5) r2 = r2.substr(1);
                        res.push_back({r1,r2});
                    }
                }
            }
        }
        
        sort(res.begin(),res.end());
        printf("%d\n", res.size());
        if(res.size())
        {
            for(auto& item : res)
            {
                printf("%s %s\n",item.first.c_str(),item.second.c_str());
            }
        }
    }
    return 0;
}