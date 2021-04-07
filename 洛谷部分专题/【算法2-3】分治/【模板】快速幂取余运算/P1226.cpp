#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

long long b,p,k;
long long ans=1;
int main()
{
    cin>>b>>p>>k;
    cout<<b<<"^"<<p<<" mod "<<k<<"=";
    while(p>0)
    {
        if(p&1)
            ans=ans*b%k;
        b=b*b%k;
        p>>=1;
    }
    printf("%d\n",ans%k);//输出
    return 0;
}