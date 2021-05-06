#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int p[N]; // 记录根节点

int cnt[N]; // 记录根节点的连通节点数量，其他节点不参与比较

int find(int x)
{
    if(x!=p[x]) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        cnt[i] = 1;
    }
    
    while (m -- )
    {
        char op[5];
        scanf("%s", op);
        if(op[0]=='C')
        {
            int a,b;
            scanf("%d%d", &a, &b);
            int roota = find(a);
            int rootb = find(b);
            if(roota == rootb) continue; //如果两节点原本就是联通的则无需进行合并和计算
            p[rootb] = p[roota]; //将 b集合加入到a集合当中
            cnt[roota] += cnt[rootb];
        }
        else if(op[0]=='Q')
        {
            if(op[1]=='1')
            {
                int a,b;
                scanf("%d%d", &a, &b);
                cout<< (find(b)==find(a) ? "Yes" : "No")<<endl;
            }
            else
            {
                int a;
                scanf("%d", &a);
                printf("%d\n",cnt[find(a)]);
            }
        }
    }
    return 0;
}