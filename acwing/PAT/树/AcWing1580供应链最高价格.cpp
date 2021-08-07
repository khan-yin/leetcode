// PAT甲级真题1090
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int N = 100010;


int n;
double P,R;
int d[N];
bool vis[N];
int p[N];
int c[N];
double price[N];


int dfs(int x)
{
    if(p[x]==-1) 
    {
        d[x] = 0;
        return d[x];
    }
    
    if(d[x]!=-1) return d[x];
    
    d[x] = dfs(p[x]) + 1;
    return d[x];
}


int main()
{
    cin>>n>>P>>R;
    // memset(p,-1,sizeof p);
    memset(d,-1,sizeof d);
    double total = 0;
    for(int i=0;i<n;i++)
    {
        int k;
        scanf("%d", &k);
        p[i]=k;
    }
    
    double maxm = 0;
    int cnt=0;
    
    for(int i=0;i<n;i++)
    {
        double m = P * pow(1+R/100,dfs(i));
         if(maxm<m)
         {
             maxm = m;
             cnt = 1;
         }
         else if(maxm==m)
         {
             cnt++;
         }
    }
    
    printf("%.2lf %d",maxm,cnt);
    return 0;
}