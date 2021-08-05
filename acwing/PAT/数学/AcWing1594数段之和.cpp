// PAT甲级真题1104
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    long double res = 0;
    for(int i=1;i<=n;i++)
    {
        double x;
        cin>>x;
        res+=x * i * (n-i+1);
    }
    printf("%.2Lf", res);
    return 0;
}