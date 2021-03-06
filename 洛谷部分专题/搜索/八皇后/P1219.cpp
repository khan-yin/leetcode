#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

int n;
bool column[20];
int cnt=0;

bool dfs(vector<int> route,int depth)
{
    if(depth==n+1)
    {
        cnt++;
        if(cnt<=3)
        {
            for(int i=1;i<=n;i++)
            {
                if(i==1)
                    printf("%d",route[i]);
                else
                {
                    printf(" %d",route[i]);
                }
            }
            printf("\n");
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(column[i])
            continue;
        bool flag=true;
        for(int row=1;row<route.size();row++)
        {
            if((row+route[row]==depth+i) || (row-route[row]+n == depth-i+n))
            {
                // cout<<"p"<<row<<" "<<route[row]<<" "<<depth<<" "<<i<<endl;
                flag=false;
                break;
            }
        }

        if(flag)
        {
            // cout<<1<<" "<<route[1]<<endl;
            route.push_back(i);
            column[i]=true;
            // cout<<depth<<" "<<i<<endl;
            dfs(route,depth+1);
            route.pop_back();
            column[i]=false;
        }
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        // cout<<"T"<<i<<endl;
        column[i]=true;
        int depth=1;
        vector<int> route;
        route.push_back(0);
        route.push_back(i);
        dfs(route,depth+1);
        column[i]=false;
    }
    printf("%d\n",cnt);
    return 0;
}