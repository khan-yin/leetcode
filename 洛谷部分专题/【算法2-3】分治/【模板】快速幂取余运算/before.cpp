#include<iostream>
using namespace std;
long long x,p,m,i,ans;
int main()
{
    cin>>x>>p>>m;
    ans=1;
    cout<<x<<"^"<<p<<" mod "<<m<<"=";
    while(p)
    {
        //cout<<"ans="<<ans<<" "<<"x="<<x<<" "<<"p="<<p<<endl;
        if(p&1)
        ans=ans*x%m;
        x=x*x%m;
        p>>=1;
        
    }
    cout<<ans%m;//<<ans<<" "<<"x="<<x<<" "<<"p="<<p<<endl;
  