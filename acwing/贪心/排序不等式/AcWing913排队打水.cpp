#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;

typedef long long LL;

int n;
int a[N];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i ++) 
        scanf("%d", &a[i]);
    sort(a+1, a + n + 1);

    // int res = 0, t = 0;
    LL res = 0, t = 0;
    for(int i = 1; i <= n; i ++)
    {
        t += a[i-1];
        res += t;
    }

    cout << res;
    return 0;
}
