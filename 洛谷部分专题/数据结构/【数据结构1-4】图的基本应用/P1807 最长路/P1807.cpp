#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;

//反向建立图和边以及入度出度，这里其实可以不涉及到出度入度因为是DAG
int map[1505][1505];
// int indegree[1505];
// int outdegree[1505];
int dp[1505];
int n,m;//n个节点，m条边
bool isWay=false;
int dfs(int node)
{
    if(node==n)
    {
        dp[node]=0;
        isWay=true;
        return dp[node];
    }

    if(dp[node]> -INF)
        return dp[node];
    
    for(int i=1;i<=n;i++)
    {
        if(map[i][node]> -INF)
        {
            // cout<<i<<"-->"<<node<<" "<<map[i][node]<<endl;
            dp[node]=max(dfs(i)+map[i][node],dp[node]);
        }
    }

    return dp[node];

}



int main()
{
    cin>>n>>m;
    memset(map,0xc0,sizeof(map));//初始化为负无穷 
    memset(dp,0xc0,sizeof(dp));
    // cout<<(-INF==0xc0)<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);//反向建立图
        // outdegree[v]++;
        // indegree[u]++;
        map[v][u]=max(map[v][u],w);
    }
    int ans = dfs(1);
    if(isWay)
        cout<<ans;
    else
        cout<<-1;
    return 0;
}