#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m;
int t[5000006];

inline int lowbit(int x)
{
    return x & -x;
}

// 单点修改 
// update node and its father node
void add(int x,int value)
{
    while(x<=n)
    {
        t[x]+=value;
        x += lowbit(x);
    }
}

 // a[1]……a[x]的和
int getsum(int x)
{
    int ans=0;
    while(x>=1)
    {
        ans+=t[x];
        x-=lowbit(x);
    }
    return ans;
}


int main()
{
    scanf("%d%d",&n,&m);
    int value;
    //init
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&value);
        add(i,value);
    }
    
    int op,x,y;
    while(m--)
    {
        
        scanf("%d%d%d",&op,&x,&y);
        if(op==1)
            add(x,y);
        else if(op==2)
            cout<<getsum(y)-getsum(x-1)<<endl;
    }
    return 0;
}