#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 100010;

struct Prop
{
    int id;
    int w;
    bool operator<(const Prop& W) const
    {
        if(w != W.w) return w > W.w;
        else return id < W.id;
    }
}p[N];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++) 
    {
        p[i].id = i;
        int v,w;
        scanf("%d%d",&v,&w);
        p[i].w = v + 2*w;
    }

    sort(p+1,p+n+1);
    
    sort(p+1,p+m+1,[](Prop p1, Prop p2) {
        return p1.id < p2.id;
    });

    for(int i=1;i<=m;i++)
    {
        printf("%d ",p[i].id);
    }

    return 0;
}