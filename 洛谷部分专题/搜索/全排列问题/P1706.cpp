#include<iostream>
#include<cstdio>
using namespace std;

int n;
int a[12];
bool isvisited[12];

void dfs(int step)
{
    if(step==n+1)
    {
        for(int i=1;i<step;i++)
        {
            printf("%5d",a[i]);
        }
        printf("\n");
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(!isvisited[i])
        {
            a[step]=i;
            isvisited[i]=true;
            dfs(step+1);
            isvisited[i]=false;
        }
    }
}




int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}