#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100006;
const int logn = 30;
int n,m;

int f[maxn][logn];


inline void query(int l,int r)
{
    int s=log2(r-l+1);
    printf("%d\n",min(f[l][s],f[r-(1 << s)+1][s]));
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&f[i][0]);
    }

    for(int j=1;j<=logn;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j] = min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    
    for(int i=1;i+m-1<=n;i++)
    {
        query(i,i+m-1);
    }
    return 0;
}