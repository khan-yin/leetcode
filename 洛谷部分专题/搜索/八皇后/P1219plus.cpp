#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int n;
bool column[100];
int cnt=0;
bool xsumy[100];
bool xsuby[100];



// void dfs(vector<int> route,int depth)
// {
//     if(depth==n+1)
//     {
//         cnt++;
//         if(cnt<=3)
//         {
//             for(int i=1;i<=n;i++)
//             {
//                 if(i==1)
//                     printf("%d",route[i]);
//                 else
//                 {
//                     printf(" %d",route[i]);
//                 }
//             }
//             printf("\n");
//         }
//     }

//     for(int i=1;i<=n;i++)
//     {
//         if(column[i]||xsumy[depth+i]||xsuby[depth-i+n])
//             continue;
//         column[i]=true;
//         xsumy[depth+i]=true;
//         xsuby[depth-i+n]=true;
//         route.push_back(i);
//         dfs(route,depth+1);
//         route.pop_back();
//         column[i]=false;
//         xsumy[depth+i]=false;
//         xsuby[depth-i+n]=false;
//     }

// }

void dfs(int* route2,int depth)
{
    if(depth==n+1)
    {
        cnt++;
        if(cnt<=3)
        {
            for(int i=1;i<=n;i++)
            {
                if(i==1)
                    printf("%d",route2[i]);
                else
                {
                    printf(" %d",route2[i]);
                }
            }
            printf("\n");
        }
    }

    for(int i=1;i<=n;i++)
    {
        if(column[i]||xsumy[depth+i]||xsuby[depth-i+n])
            continue;
        column[i]=true;
        xsumy[depth+i]=true;
        xsuby[depth-i+n]=true;
        route2[depth]=i;
        dfs(route2,depth+1);
        route2[depth]=0;
        column[i]=false;
        xsumy[depth+i]=false;
        xsuby[depth-i+n]=false;
    }

}

int route2[100];

int main()
{
    scanf("%d",&n);
    vector<int> route;
    route.push_back(0);
    // dfs(route,1);
    dfs(route2,1);
    printf("%d\n",cnt);
    return 0;
}