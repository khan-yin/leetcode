#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];
int s[N];

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i ++ ) s[i] = s[i-1] + a[i];
    
    while (m -- )
    {
        int l,r;
        scanf("%d%d", &l, &r);
        printf("%d\n",s[r]-s[l-1]);
    }
    
    return 0;
}