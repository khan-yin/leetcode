#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstdlib>
#include<cstring>
using namespace std;

vector<int> node_list[100005];
bool isvisited[100005];
int targetNode[100005];

void dfs(int node,int target)
{
    if(isvisited[node] || targetNode[node]>0) return;
    isvisited[node]=true;
    targetNode[node]=target;
    for(int i : node_list[node])
        dfs(i,target);  
}

int main()
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int from,to;
        cin>>from>>to;
        //求能到达的编号最大的点，且为有向图，则反向建立边
        node_list[to].push_back(from);
    }
    //从最大的节点反向遍历
    for(int i=n;i>0;i--)
    {
        memset(isvisited,false,sizeof(isvisited));
        dfs(i,i);
    }

    for(int i=1;i<=n;i++)
    {
        cout<<targetNode[i]<<" ";
    }


    return 0;
}