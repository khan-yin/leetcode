#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

//求n的二进制表示中第k位数字: n >> k & 1
//返回n的最后一位1：lowbit(n) = n & -n
inline int lowbit(int x)
{
    return x & -x;
}


int main()
{
    int n,m;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ )
    {
        scanf("%d", &m);
        int res=0;
        while (m) m-=lowbit(m), res++;//每次减去最后一位1，就相当于记录这个数字中出现了多少位1
        printf("%d ",res);
    }
    
    return 0;
}