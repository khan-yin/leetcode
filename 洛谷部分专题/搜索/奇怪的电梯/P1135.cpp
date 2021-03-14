#include<iostream>
#include<cstdio>
using namespace std;

int n,a,b;
int home[205];
int cnt=-1;
bool isvisited[205];
// void dfs(int index,int step)
// {
//     if(index == b)
//     {
//         if(cnt==-1)
//             cnt=step;
//         else
//             cnt = cnt>step?step:cnt;
//         return;
//     }
//     else
//     {
//         isvisited[index]=true;
//         if(!isvisited[index+home[index]]&&index+home[index]<=n) dfs(index+home[index],step+1);
//         if(!isvisited[index-home[index]]&&index-home[index]>0) dfs(index-home[index],step+1);
//         isvisited[index]=false;//回溯
//     }
// }

void dfs(int index,int step)
{
    if(cnt>=0&&step>cnt)//剪枝
        return;
    if(index == b)
    {
        if(cnt==-1)
            cnt=step;
        else
            cnt = cnt>step?step:cnt;
        return;
    }
    else
    {
        isvisited[index]=true;
        if(!isvisited[index+home[index]]&&index+home[index]<=n) dfs(index+home[index],step+1);
        if(!isvisited[index-home[index]]&&index-home[index]>0) dfs(index-home[index],step+1);
        isvisited[index]=false;//回溯
    }
}

int main()
{
    scanf("%d %d %d",&n,&a,&b);
    for(int i=1;i<=n;i++)
        scanf("%d",&home[i]);
    //既然是最少就不会走回头路
    dfs(a,0);
    printf("%d",cnt);

    return 0;
}