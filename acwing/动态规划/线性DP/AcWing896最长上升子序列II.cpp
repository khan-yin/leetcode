#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int a[N];
int q[N];//q[i]表示长度为i的最长上升子序列的结尾的数的最小值

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    
    q[0] = a[1];
    int len = 0;
    for(int i=1;i<=n;i++)
    {
        int l = 0, r = len;
        while(l<r)
        {
            int mid = l + r + 1 >> 1;
            if(q[mid]<a[i]) l = mid;
            else r = mid -1;
        }
        len = max(len,l+1);
        q[l+1] = a[i];
    }
    
    cout<<len<<endl;
    return 0;
}