#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int logn = 21;
const int maxn = 2000001;
int f[maxn][logn + 1], Logn[maxn + 1];

inline int read()
{
    int x=0,f=1;
    char ch = getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')
            f=-1;
        ch = getchar();
    }

    while(isdigit(ch))
    {
        x=x*10+ch-48; //'0'
        ch=getchar();
    }
    return x*f;
}

int n,m;

int main()
{
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
        f[i][0]=read();
    
    for(int j=1;j<=logn;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);

    while(m--)
    {
        int l=read(),r=read();
        int s=log2(r-l+1);
        printf("%d\n",max(f[l][s],f[r-(1<<s)+1][s]));
    }

    return 0;
}