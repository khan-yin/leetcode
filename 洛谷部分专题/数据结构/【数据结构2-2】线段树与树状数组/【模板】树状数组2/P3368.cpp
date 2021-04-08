#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define ll long long
using namespace std;

int n,m;
ll b[500006];//维护一个差分，实现区间修改，和单点查询
inline ll lowbit(ll x)
{
    return  x & -x;
}

inline void add(int x,ll value)
{
    while(x<=n)
    {
        b[x]+=value;
        x+=lowbit(x);
    }
}
 
// a[x]=b[1]+...+b[x] 差分的和即为a[x]的值
inline ll getsum(int x)
{
    ll ans=0;
    while(x>=1)
    {
        ans += b[x];
        x-=lowbit(x);
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    ll last = 0, now;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&now);
        add(i,now-last);
        last = now;
    }

    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int l,r;
            ll k;
            scanf("%d%d%lld",&l,&r,&k);
            // b[l] = a[l] - a[l-1] => (a[l]+k) - a[l-1] 
            // => b[l] = b[l] + k
            add(l,k);
            // b[r+1] = b[r+1] - b[r] => b[r+1] - (b[r]+k) 
            // => b[r] = b[r] - k
            add(r+1,-k);
        }
        else if(op==2)
        {
            int x;
            scanf("%d",&x);
            cout<<getsum(x)<<endl;
        }
    }
}