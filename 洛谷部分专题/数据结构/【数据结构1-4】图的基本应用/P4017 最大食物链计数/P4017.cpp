#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> chain[5005];
bool isvisited[5005];
int indegree[5005];
int outdegree[5005];


long long dp[5005];

long long ans=0;

//记忆化搜索
long long dp_dfs(int node)
{
    if(dp[node]>0)
        return dp[node];
    else if(indegree[node]==0)//是生产者则为1
    {
        dp[node]=1;
        return dp[node];
    }

    for(int i:chain[node])
    {
        // cout<<node<<"--"<<i<<endl;
        dp[node]+=dp_dfs(i);
        dp[node]%=80112002;
    } 
    return dp[node];
}

//单纯暴力dfs会TLE
void dfs(int node)
{

    // cout<<node<<endl;
    if(outdegree[node]==0)//是最后的消费者
    {
        ans++;
        return;
    }
    long long step=1;
    
    for(int i:chain[node])
    {
        if(!isvisited[i])
        {
            isvisited[i]=true;
            dfs(i);
            isvisited[i]=false;
        }
    }  
}

//求错了一直以为是求最长的食物链
// long long dfs(int node)
// {
//     // cout<<node<<endl;
//     if(outdegree[node]==0)//是最后的消费者
//     {
//         return 1;
//     }
//     long long step=1;
    
//     for(int i:chain[node])
//     {
//         long long temp=1;
//         if(!isvisited[i])
//         {
//             isvisited[i]=true;
//             step=max(temp+dfs(i),step);
//             isvisited[i]=false;
//         }
//     }
//     // cout<<"temp:"<<node<<" "<<step<<endl;
//     return step;   
// }

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;//被吃，吃
        cin>>a>>b;
        // chain[a].push_back(b); //常规dfs正向建图 
        chain[b].push_back(a);//在记忆化搜索当中，我是反向建图的方便查找
        outdegree[a]++;
        indegree[b]++;
    }
    
    for(int i=1;i<=n;i++)
    {
        // long long step=1;
        if(outdegree[i]==0)//最后的消费者
        {
            // cout<<"a"<<i<<endl;
            ans+=dp_dfs(i);
            ans%= 80112002;
            // isvisited[i]=true;
            // cout<<i<<"-"<<dp_dfs(i);
            // isvisited[i]=false;
        }
    }
    
    cout<<ans<<endl;

    return 0;
}