#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 250000;

int dp[N];
int v[N],w[N];



int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    
    //将原来的样本数量进行二进制优化，将连续的数量选择变化转换成每个2进制划分的离散01背包选择问题
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int a,b,s;
        scanf("%d%d%d", &a, &b,&s);
        int k=1;
        while(k<=s)
        {
            cnt++;
            v[cnt] = k*a;
            w[cnt] = k*b;
            s -= k;
            k*=2;
        }
        
        if(s>0)
        {
            cnt++;
            v[cnt] = a*s;
            w[cnt] = b*s;
        }
    }
    
    //注意这里的物品数量变成了划分后的数量cnt，然后每个部分是一个01背包就能组合出连续0-s的数量选择方式
    for(int i=1;i<=cnt;i++)
        for(int j=m;j>=v[i];j--)
            dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
    
    cout<<dp[m]<<endl;
    return 0;
}