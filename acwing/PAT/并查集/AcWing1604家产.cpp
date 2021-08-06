// PAT甲级真题1114
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 10100;

int p[N];
int c[N];
int hc[N];
int ha[N];
bool vis[N];

struct Edge
{
    int x;
    int y;
}e[N];

int find(int x)  // 并查集
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

struct Family
{
    int id,c,hc,ha;
    bool operator<(Family& w) const
    {
        // ha /c < w.ha / w.c
        if(ha * w.c != w.ha * c) return ha * w.c > w.ha * c;
        return id < w.id;
    }
};

int main()
{
    // ID Father Mother k Child_1 ... child_k M_estate Area
    int n;
    scanf("%d", &n);
    int cnt=0;
    for(int i=0;i<N;i++) 
    {
        p[i]=i;
        c[i]=1;
    }
    while (n -- )
    {
        int id,father,mother,k;
        cin>>id>>father>>mother>>k;

        vis[id]=true;
        if(father!=-1)
        {
            e[cnt++]={id,father};
        }

        if(mother!=-1)
        {
            e[cnt++]={id,mother};
        }

        for(int i=0;i<k;i++) 
        {
            int child;
            scanf("%d", &child);
            e[cnt++]={id,child};
        }

        cin>>hc[id]>>ha[id];
    }


    for(int i=0;i<cnt;i++)
    {
        int x = e[i].x;
        int y = e[i].y;
        vis[x] = vis[y] = true;
        int px = find(x);
        int py = find(y);
        if(px==py) continue;
        if(px>py) swap(px,py);
        p[py] = px;
        c[px]+=c[py];
        ha[px]+=ha[py];
        hc[px]+=hc[py];
    }


    vector<Family> family;

    for(int i=0;i<N;i++)
    {
        if(p[i]==i && vis[i])
        {
            // cout << i<<endl;
            family.push_back({i,c[i],hc[i],ha[i]});
        }
    }

    sort(family.begin(),family.end());

    cout<<family.size()<<endl;
    for(auto& item : family)
    {
        printf("%04d %d %.3lf %.3lf\n",item.id,item.c,item.hc*1.0 / item.c,item.ha*1.0 /item.c);
    }


    return 0;
}