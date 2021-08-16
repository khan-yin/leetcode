class Solution {
public:
    bool vis[20];
    int n;
    int cnt=0;
    void dfs(int step)
    {
        if(step==n+1)
        {
            cnt++;
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i]) continue;
            if(i%step==0 || step%i==0)
            {
                vis[i]=true;
                dfs(step+1);
                vis[i]=false;
            }
        }
        
    }
    int countArrangement(int n) {
        this->n = n;
        dfs(1);
        return cnt;
    }
};