#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int px[4]={-1,1,0,0};
    int py[4]={0,0,1,-1};
    int vis[55][55];
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        queue<pair<int,int>> q;
        q.push({startRow,startColumn});
        long long cnt = 0;
        int mod = 1e9+7;
        while(maxMove--)
        {
            int sz = q.size();
            for(int k=0;k<sz;k++)
            {
                auto t = q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nx = t.first + px[i];
                    int ny = t.second + py[i];
                    if(nx>=0&&ny>=0&&nx<m&&ny<n)
                    {
                        q.push({nx,ny});
                        vis[nx][ny]++;
                    }
                    else
                    {
                        cnt++;
                    }
                }
            }
             
        }
        return cnt % mod;
    }
};