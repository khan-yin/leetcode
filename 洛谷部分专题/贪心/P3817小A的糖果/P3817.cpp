#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long x;

long long box[100006];
int main()
{
    cin>>n;
    cin>>x;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&box[i]);
    }
    long long ans=0;
    //单个超项
    if(box[1]>x)
    {
        ans+=box[1]-x;//增加吃的量
        box[1]=x;//a[i]>=x,要吃的最少，即是a[i]=x;
    }
    
    for(int i=2;i<=n;i++)
    {
        if(box[i-1]+box[i]>x)
        {
            ans+=(box[i-1]+box[i]-x);
            box[i]=x-box[i-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}