#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

int a[N];


int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++ )
        scanf("%d",&a[i]);
    //手动实现next_permutation
    while (m -- )
    {
        // 1. 从后往前找第一个a[k]<a[k+1]的位置
        int k = n -2;
        while(a[k]>a[k+1]) k--;
        
        // 2. 在a[k+1..n]中找到比a[k]大的里面最小的数a[t]
        int t = k;
        while(t+1<n&&a[t+1]>a[k]) t++;
        
        // 3. 交换a[k]和a[t]，则a[k+1...n]数组是单调递减的
        swap(a[k],a[t]);
        // 4. 将a[k+1...n]翻转成升序
        reverse(a+k+1,a+n);
    }
    
    for (int i = 0; i < n; i ++ )
        printf("%d ",a[i]);
    
    return 0;
}