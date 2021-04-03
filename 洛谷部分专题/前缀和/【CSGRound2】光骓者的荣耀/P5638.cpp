#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

long long nodesum[1000006];
int main()
{
    int n,k;
    cin>>n>>k;
    if(k>=n-1)
    {
        cout<<0;
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        long long route;
        cin>>route;
        nodesum[i]=nodesum[i-1]+route;
    }
    long long maxlen=nodesum[k];

    for(int i=2;i<=n-k;i++)
    {
        maxlen=max(maxlen,nodesum[i+k-1]-nodesum[i-1]);
    }

    cout<<nodesum[n-1]-maxlen;


    return 0;
}