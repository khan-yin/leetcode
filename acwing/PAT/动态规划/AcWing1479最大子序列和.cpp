// PAT甲级真题1007
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010;
const int inf = 0x3f3f3f3f;


int a[N];
int dp[N]; // dp[i] 表示的以i结尾的最大子序和

int main()
{
    int k;
    cin>>k;
    bool flag=true;
    for(int i=1;i<=k;i++)
    {
        scanf("%d", &a[i]);
        dp[i] = a[i];
        if(a[i]>=0) flag=false;
    }
    
    if(flag)
    {
        cout<<0<<' '<<a[1]<<' '<<a[k]<<endl;
        return 0;
    }
 
    int l = a[1], r = a[k], res=dp[1];
    int tl = l;
    for(int i=2;i<=k;i++)
    {
        dp[i] = max(dp[i],dp[i-1] + a[i]);
        if(dp[i-1]+a[i]<dp[i]) tl = a[i];
        if(dp[i]>res)
        {
            l = tl;
            r = a[i];
            res = dp[i];
        }
    }

    cout<<res<<' '<<l<<' '<<r<<endl;
    return 0;
}