// PAT甲级真题1113
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;
typedef long long LL;

LL a[N];
LL S1,S2;

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++) scanf("%lld", &a[i]);
    
    sort(a,a+n);
    int mid = n/2;
    
    for(int i=0,j=n-1;i<j;i++,j--)
    {
        S1 += a[i];
        S2 += a[j];
    }
    LL res = abs(S1 - S2);
    
    if(n&1)
    {
        res = max(res,abs(S1+a[mid] - S2));
        res = max(res,abs(S2+a[mid] - S1));
    }
    
    printf("%lld %lld",n&1,res);
    
    
    return 0;
}