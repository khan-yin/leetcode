#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 10;
int n;

int a[N];
bool isvisited[N];


void dfs(int index)
{
    if(n==index)//递归出口
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
    }

    for(int i=1;i<=n;i++)
    {
        if(isvisited[i]) continue;
        a[index] = i;//给当前位置赋值
        isvisited[i] = true;
        dfs(index+1);
        a[index] = 0;
        isvisited[i] = false;
    }
    
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    dfs(0);
    return 0;
}