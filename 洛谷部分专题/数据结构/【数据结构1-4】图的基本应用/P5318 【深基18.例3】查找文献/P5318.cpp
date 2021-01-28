#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<queue>

using namespace std;


// vector< > node_list;//邻接表,用set是因为需要排序
set<int> node_list[1000005];
// vector<bool> isvisted;//是否访问
bool isvisited[1000005];

void dfs(int node)
{
    if(isvisited[node])
        return;
    else
    {
        isvisited[node]=true;
        cout<<node<<" ";
        for(int i : node_list[node])
        {
            if(!isvisited[i])
                dfs(i);
        }
    }
}


void bfs(int node)
{
    queue<int> q;
    if(!isvisited[node])
        q.push(node);
    isvisited[node]=true;
    while(!q.empty())
    {
        // int size = q.size();
        int s=q.front(); 
        q.pop();//拿出队列首的那个点
        cout<<s<<" ";
        for(int i:node_list[s])
        {
            
            if(!isvisited[i])
            {
                // cout<<s<<" "<<i<<endl;
                q.push(i);
                isvisited[i]=true;
            }
                
        }
    }
}

int main()
{
    int n,m;//node counts & edge counts
    cin>>n>>m;

    // node_list.resize(n+1);
    // isvisted.resize(n+1, false);
    
    // input edge information
    for(int i=1;i<=m;i++)
    {
        int from,to;
        cin>>from>>to;
        node_list[from].insert(to);
    }  

    dfs(1);
    cout<<endl;
    for(int i=1;i<=n;i++)
        isvisited[i]=false;
    bfs(1);


    
    return 0;
}