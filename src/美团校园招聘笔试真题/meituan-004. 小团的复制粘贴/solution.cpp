#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 200010;

int a[N];
int b[N];
int n;

int main()
{
    scanf("%d",&n);

    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    memset(b,-1,sizeof b);
    int m;
    scanf("%d",&m);

    while(m--)
    {
        int op;
        scanf("%d",&op);
        if(op==1)
        {
            int k,x,y;
            scanf("%d%d%d",&k,&x,&y);
            for(int i =0;i<k;i++)
            {
                b[y+i]=a[x+i];
            }
        }
        else
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",b[x]);
        }

    }
    return 0;
}