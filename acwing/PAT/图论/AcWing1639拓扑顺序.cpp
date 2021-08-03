// PAT甲级真题1146
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;
const int M = 10010;

struct Edge
{
    int a;
    int b;
}e[M];

bool vis[N];
int p[N];
int n,m;

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d", &e[i].a,&e[i].b);
    }
    int k;
    scanf("%d", &k);
    vector<int> res;
    for(int i=0;i<k;i++)
    {
        int x;
        for(int j=1;j<=n;j++)
        {
            scanf("%d", &x);
            p[x] = j;
        }

        bool flag =true;

        for(int j=0;j<m;j++)
        {
            if(p[e[j].a] > p[e[j].b])
            {
                flag = false;
                break;
            }
        }

        if(!flag)
        {
            res.push_back(i);
        }
    }

    cout<<res[0];
    for(int i=1;i<res.size();i++) printf(" %d",res[i]);
    return 0;
}