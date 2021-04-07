#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,c;
int a[200001];


int main()
{
    long long cnt=0;// long long 卡掉
    cin>>n>>c;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);

    for(int i=0;i<n;i++)
    {
        //二分搜索
        int r = upper_bound(a,a+n,a[i]+c)-a;
        int l = lower_bound(a,a+n,a[i]+c)-a;
        cnt+=(r-l);
    }
    //会卡3个点TLE
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=n-1;j>i;j--)
    //     {
    //         if(a[j]-a[i]<c)
    //             break;
    //         else if(a[j]-a[i]==c)
    //             cnt++;
    //     }
    // }
    cout<<cnt<<endl;
    return 0;
}