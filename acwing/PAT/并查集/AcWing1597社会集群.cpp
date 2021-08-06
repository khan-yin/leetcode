// PAT甲级真题1107
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 10100;

int p[N];
int n;
int c[N];



unordered_map<int,vector<int> > mp;


int find(int x)  // 并查集
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}


int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        int m;
        scanf("%d:", &m);
        // cout<<m<<':';
        while(m--)
        {
            int x;
            scanf("%d", &x);
            // cout<<x<<' ';
            mp[x].push_back(i);
        }
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        c[i]=1;
    }
    // cout<<mp.size()<<endl;
    for(auto item : mp)
    {
        vector<int> pt = item.second;
        // cout<<item.first<<":";
        // for(int k : p) cout<<' '<<k;
        // cout<<endl;
        for(int i=1;i<pt.size();i++)
        {
            
            int a = pt[i-1];
            int b = pt[i];
            // cout<<a<<' '<<b<<endl;
            int pa = find(a);
            int pb = find(b);

            if(pa!=pb) 
            {
                p[pb] = pa;
                c[pa]+=c[pb];
            }

        }
        
    }
    
    vector<int> res;
    for(int i=1;i<=n;i++)
    {
        if(p[i]==i) res.push_back(c[i]);
    }
    
    sort(res.begin(),res.end(),greater<int>());
    if(!res.size()) return 0;
    cout<<res.size()<<endl;
    cout<<res[0];
    for(int i=1;i<res.size();i++) cout<<' '<<res[i];
    
    return 0;
}