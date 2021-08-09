// PAT甲级真题1046
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010;

int d[N];
int sum[N];


int main()
{
    int n,m;
    scanf("%d", &n);
    
    for(int i=1;i<=n;i++) 
    {
        scanf("%d", &d[i]);
        sum[i] = sum[i-1] + d[i-1];
    }
    int total = sum[n] + d[n];

    scanf("%d", &m);
    while(m--)
    {
        int a,b;
        scanf("%d%d", &a, &b);
        if(a>b) swap(a,b);
        int dis = sum[b] - sum[a];
        
        printf("%d\n",min(dis,total-dis));
    }
    return 0;
}