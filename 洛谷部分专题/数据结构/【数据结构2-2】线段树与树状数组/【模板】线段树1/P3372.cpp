#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;

const int MAXN = 100005;
ll a[MAXN],d[MAXN*4],b[MAXN*4];
// a[]: origin array
// d[]: segment tree
// b[]:lazy tag

// left child
inline ll lson(ll p) // params =>position: the node number
{
    return p<<1; //2n
}

// right child
inline ll rson(ll p)  // params =>position: the node number
{
    return (p << 1)|1; //2n+1
}

// update father node from its son node
inline void pushup(ll p)
{
    d[p] = d[lson(p)]+d[rson(p)];
}



inline void build(ll l,ll r,ll p)
{
    if(l==r)
    {
        d[p]=a[l];
        return;
    }
    
    // ll mid = (l+r)/2;
    ll mid = (l+r)>>1;

    // build left tree
    build(l,mid,lson(p));
    // build right tree
    build(mid+1,r,rson(p));

    pushup(p);
}


inline void pushdown(ll p,ll s,ll mid,ll t)
{
    if(b[p])
    {
        
        d[p<<1] += (mid-s+1)*b[p]; // update left tree
        d[(p<<1)|1] += (t-mid)*b[p];  // update right tree
        b[p<<1] += b[p]; // update left lazy tag tree
        b[(p<<1)|1] += b[p]; // update right lazy tag tree
    }
    b[p]=0;
}

// a[left,right]+=c //s,t for tree boundary to update
inline void update(ll left,ll right,ll c,ll s,ll t,ll p)
{
    // [s,t] is in [left,right]
    if(left<=s&&t<=right)
    {
        d[p] += (t-s+1)*c;
        b[p] +=c;//update lazy tag
        return;
    }

    ll mid = (s + t) >> 1;
    // ll mid = (s+t)>>1;

    pushdown(p,s,mid,t);

    if(left<=mid)
        update(left,right,c,s,mid,p<<1);
    if(right>mid)
        update(left,right,c,mid+1,t,(p<<1)|1);
    
    pushup(p);
}

// sum(a[left...right])
ll getsum(ll left,ll right,ll s,ll t,ll p)
{
    if(left<=s&&t<=right)
    {
        return d[p];
    }

    ll mid = (s+t)>>1;

    // check lazy======tag push down 
    pushdown(p,s,mid,t);

    ll ans=0;
    if(left<=mid)
        ans +=getsum(left,right,s,mid,p<<1);
    if(right>mid)
        ans += getsum(left,right,mid+1,t,(p<<1)|1);
    
    return ans;
}

int main()
{
    ll n,m;
    std::ios::sync_with_stdio(0);

    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }

    build(1,n,1);// init left,right,position=1

    while(m--)
    {
        ll op;
        ll x,y,k;
        cin>>op>>x>>y;
        if(op==1)
        {
            cin>>k;
            update(x,y,k,1,n,1);
        }
        else if(op==2)
            cout<<getsum(x,y,1,n,1)<<endl;
    }
    return 0;
}