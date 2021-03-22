#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
public:
    int cnt=0;
    bool isvisited[105][105];
    int row;
    int col;
    int dx[5]={0,-1,1,0,0};
    int dy[5]={0,0,0,1,-1};
    void dfs(int x,int y,int k)
    {
        int total = x/10+x%10+y/10+y%10;
        if(x<0||x>=this->row||y<0||y>=this->col||isvisited[x][y]||total>k)
            return;
        this->isvisited[x][y]=true;
        cnt++;
        for(int i=1;i<=4;i++)
        {
            dfs(x+dx[i],y+dy[i],k);
        }
    }
    // m行n列
    int movingCount(int m, int n, int k) {
        if(k==0)
            return 1;
        this->row = m;
        this->col = n;
        dfs(0,0,k);
        return cnt;
    }
};