// PAT甲级真题1101
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
int n;
int a[N];
int dpmin[N];
int dpmax[N];
int my[N];

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++) scanf("%d", &a[i]);

    dpmax[1] = a[1];
    for(int i=1;i<=n;i++)
    {
        dpmax[i] = max(dpmax[i-1],a[i]);
    }

    dpmin[n] = a[n];
    for(int i=n;i>=1;i--)
    {
        dpmin[i-1] = min(dpmin[i],a[i]);
    }

    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=dpmax[i] && a[i] <= dpmin[i]) my[cnt++]=a[i];
    }

    cout<<cnt<<endl;
    if(cnt==0)
    {
        cout<<endl;
        return 0;
    }
    cout<<my[0];
    for(int i=1;i<cnt;i++)  cout<<' '<<my[i];
    return 0;
}