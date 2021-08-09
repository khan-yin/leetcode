// PAT甲级真题1085
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N];
int n,p;
int M,m;
// 如果 M≤m×p 成立，则该序列被称为完美序列，其中 M 和 m 分别是序列中的最大和最小数。


int main()
{
    scanf("%d%d", &n, &p);
    
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    sort(a+1,a+n+1);
    
    int res = 0;
    for(int i=1,j=1;i<=n;i++)
    {
        while((long long)a[j]*p<a[i]) j++;
        res = max(res,i-j+1);
    }
    cout<<res<<endl;
    return 0;
}