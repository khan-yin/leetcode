// PAT甲级真题1053
#include<iostream>
#include<cstdio>
#include<cstring>
#include <algorithm>
#include<string>
#include<vector>

using namespace std;

const int N = 200;
int n,m,s;

int g[N][N];

int w[N];
vector<vector<int>> res;
void dfs(int root,vector<int> path,int sum)
{
    bool is_leaf = true;
    for(int i=0;i<n;i++) 
    {
        if(g[root][i]) 
        {
            is_leaf=false;
            break;
        }
    }
    sum +=w[root];
    if(sum>s) return;
    
    if(is_leaf)
    {
        if(sum==s)
        {
            path.push_back(w[root]);
            res.push_back(path);
            return;
        }
    }
    else
    {
        for(int i=0;i<n;i++) 
        {
            if(g[root][i]) 
            {
                path.push_back(w[root]);
                dfs(i,path,sum);
                path.pop_back();
            }
        }
    }
    
    
}

int main()
{
    scanf("%d%d%d", &n, &m, &s); // 分别表示树的总节点数量，非叶子节点数量，给定权重数字。
    for(int i=0;i<n;i++) scanf("%d", &w[i]);
    
    for(int i=0;i<m;i++)
    {
        int id,k;
        scanf("%d%d", &id, &k);
        for(int j=0;j<k;j++)
        {
            int to;
            scanf("%d", &to);
            g[id][to] = 1;
        }
    }
    
    int root = 0;
    vector<int> path;
    int sum = 0;
    dfs(root,path,sum);
    
    sort(res.begin(),res.end(),greater<vector<int>>());
    
    for(auto& p : res)
    {
        printf("%d",p[0]);
        for(int i=1;i<p.size();i++) printf(" %d",p[i]);
        printf("\n");
    }
    
    return 0;
}