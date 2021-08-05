// PAT甲级真题1063
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;

const int N = 10010;
int n;
int m;
int k;

unordered_set<int> S[N];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &m);
        for(int j=1;j<=m;j++)
        {
            int x;
            cin>>x;
            S[i].insert(x);
        }
    }

    scanf("%d", &k);
    while(k--)
    {
        int a,b;
        scanf("%d%d", &a,&b);
        int cnt=0;
        for(int item : S[a])
        {
            cnt+=S[b].count(item);
        }
        int total = S[a].size() + S[b].size() - cnt;
        printf("%.1lf%%\n", (double)cnt / total * 100);

    }

    return 0;
}