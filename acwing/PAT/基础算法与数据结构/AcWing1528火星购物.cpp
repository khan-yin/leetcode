// PAT甲级真题1044
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100010, inf = 1e9;

int a[N];
int s[N];

int n,m;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    int res = inf;

    for(int i=1,j=0;i<=n;i++)
    {
        while(s[i] - s[j+1] >=m) j++;
        if (s[i] - s[j] >= m) res = min(res, s[i] - s[j]);
    }

    for (int i = 1, j = 0; i <= n; i ++ )
    {
        while (s[i] - s[j + 1] >= m) j ++ ;
        if (s[i] - s[j] == res) printf("%d-%d\n", j + 1, i);
    }

    return 0;
}