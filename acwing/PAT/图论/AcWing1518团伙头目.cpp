// PAT甲级真题1034
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int N = 1010;

int n,k;

unordered_map<string,vector<pair<string,int>> > g;
unordered_map<string,int> total;
unordered_map<string,bool> vis;


void dfs(string x, vector<string>& path)
{
    vis[x]=true;
    auto& nodes = g[x];
    path.push_back(x);
    for(auto& item : nodes)
    {
        string to = item.first;
        if(!vis[to]) dfs(to,path);
    }
}

bool cmp(string &a,string &b)
{
    return total[a]>total[b];
}

int main()
{
    scanf("%d%d", &n,&k);
    
    for(int i=0;i<n;i++)
    {
        string a,b;
        int c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        total[a]+=c;
        total[b]+=c;
    }
    
    
    vector<pair<string,int>> res;
    
    for(auto& it : g)
    {
        string name = it.first;
        if(vis[name]) continue;
        vector<string> path;
        dfs(name,path);
        int sum = 0;
        for(auto& item : path) sum +=total[item];
        sum /=2;
        if(path.size()>=3&&sum>k) 
        {
            sort(path.begin(),path.end(),cmp);
            string boss = path[0];
            res.push_back({boss,path.size()});
        }    
    }
   
    
    sort(res.begin(),res.end());
    
    cout<<res.size()<<endl;
    for(auto& item : res)
    {
        cout<<item.first<<' '<<item.second<<endl;
    }
    
    return 0;
}