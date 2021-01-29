#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n;//节点
bool map[10005][10005];
int cost[10005];
int indegree[10005];
int timedp[10005];

int topo()
{
    int ans=0;
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
            timedp[i]=cost[i];
        }
    }

    while(!q.empty())
    {
        int node =q.front();
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(map[node][i])
            {
                if(--indegree[i]==0)
                    q.push(i);
                timedp[i]=max(timedp[i],timedp[node]+cost[i]);
            }
        }
    }
    for(int i=1;i<=n;++i)
        ans = max(ans,timedp[i]);
    return ans;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int node,c,before;
        cin>>node>>c;
        cost[node]=c;
        while(cin>>before)
        {
            if(before==0)
                break;
            map[before][node]=true;
            indegree[node]++;
        }

    }
    int ans =topo();
    printf("%d",ans);
    return 0;
}