// PAT甲级真题1013
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1010;
const int M = 5e5 + 10;

int n,m,k;
int p[N];

struct Edge
{
    int a;
    int b;
}e[M];



int find(int x)
{
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d", &e[i].a, &e[i].b);
    }

    while (k -- )
    {
        int x;
        scanf("%d", &x);
        for(int i=1;i<=n;i++) p[i]=i;
        int cnt=n-1;
        for(int i=0;i<m;i++)
        {
            int a = e[i].a;
            int b = e[i].b;
            int pa = find(a);
            int pb = find(b);
            if(a!=x && b!=x && pa!=pb)
            {
                p[pa]=pb;
                cnt--;
            }
        }

        printf("%d\n",cnt-1);
    }
    
    return 0;
}