#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N],b[N];



int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d",&a[i]); // 原数组
    //差分 b[1]=a[1],b[2]=a[2]-a[1] ====> b[i] = a[i] - a[i-1]
    for (int i = 1; i <= n; i ++ ) b[i] = a[i] - a[i-1]; 
    
    while (m -- )
    {
        int l,r,c;
        scanf("%d%d%d", &l, &r, &c);
        // 表示将序列中 [l,r] 之间的每个数加上 c ====> b[l]+=c b[r+1]-=c
        b[l]+=c;
        b[r+1]-=c;
    }
    
    for (int i = 1; i <= n; i ++ ) a[i] = a[i-1] + b[i];
    for (int i = 1; i <= n; i ++ ) printf("%d ",a[i]);
    
    return 0;
}