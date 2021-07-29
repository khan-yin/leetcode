// PAT甲级真题1064
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010, M = 2*N +10;

int h[M];
int a[N];
int n;
int cnt=0;

//中序遍历填充数据
void dfs(int x)
{
    if(2*x <=n) dfs(2*x);
    h[x] = a[cnt++];
    if(2*x+1<=n) dfs(2*x+1);
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    dfs(1);
    cout<<h[1];
    for(int i=2;i<=n;i++)cout<<' '<<h[i]; 
    
    return 0;
}