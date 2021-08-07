// PAT甲级真题1037
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int N = 100010;

int a[N];
int b[N];

int main()
{
    int n;
    int m;
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    for(int i=0;i<m;i++) scanf("%d", &b[i]);
    
    int res = 0;
    
    sort(a,a+n);
    sort(b,b+m);
    
    for(int i=0,j=0;i<n&&j<m&&a[i]<0&&b[j]<0;i++,j++)
    {
        // cout<<a[i]<<' '<<b[j]<<endl;
        res += a[i]*b[j];
    }
    
    for(int i=n-1,j=m-1;i>=0&&j>=0&&a[i]>0&&b[j]>0;i--,j--)
    {
        // cout<<a[i]<<' '<<b[j]<<endl;
        res += a[i]*b[j];
    }
    
    cout<<res;
    
    return 0;
}