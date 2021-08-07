// PAT甲级真题1125
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10010;

double a[N];

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i=0;i<n;i++)
    {
        scanf("%lf", &a[i]);
    }
    
    sort(a,a+n);
    
    double res = a[0];
    
    for(int i=1;i<n;i++)
    {
        res = (res + a[i]) / 2;
    }
    
    cout<<(int)res;
    return 0;
}