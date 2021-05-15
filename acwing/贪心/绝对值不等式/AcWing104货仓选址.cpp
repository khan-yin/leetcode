#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;


const int N = 100000;
int a[N];

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    
    //排序
    sort(a+1,a+n+1);
    int mid = a[n/2+1];//中位数
    int res = 0;
    for(int i=1;i<=n;i++)
        res += abs(mid - a[i]);
    
    cout<<res<<endl;
    
    return 0;
}