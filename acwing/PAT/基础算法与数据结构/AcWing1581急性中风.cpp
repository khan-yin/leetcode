// PAT甲级真题1091
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int M = 1286 , N = 128 , L = 60 ;
int m,n,l,T;

int a[L][M][N];
bool vis[L][M][N];

const int direct[6][3]= { 
    {-1,0,0}, // 前
    {1,0,0},// 后
    {0,-1,0}, // 上
    {0,1,0}, // 下
    {0,0,-1}, // 左
    {0,0,1} // 右
};

struct Node
{
    int z;
    int x;
    int y;
};



int dfs(int x,int y,int z)
{
    if(!a[x][y][z])
    {
        return 0;
    }
    vis[x][y][z]=true;
    int res = 1;
    for(int i=0;i<6;i++)
    {
        int nx = x + direct[i][0];
        int ny = y + direct[i][1];
        int nz = z + direct[i][2];
        if(nx>=0&&nx<m&&ny>=0&&ny<n&&nz>=0&&nz<l&&!vis[nx][ny][nz]&&a[nx][ny][nz])
            res+=dfs(nx,ny,nz);
    }
    return res;
}


int bfs(int z, int x, int y)
{
    queue<Node> q;
    q.push({z,x,y});
    int cnt = 1;
    vis[z][x][y]=true;
    while(q.size())
    {
        auto t = q.front();
        q.pop();
        for(int d=0;d<6;d++)
        {
            int nz = t.z + direct[d][0];
            int nx = t.x + direct[d][1];
            int ny = t.y + direct[d][2];
            if(nx>=0&&nx<m&&ny>=0&&ny<n&&nz>=0&&nz<l&&!vis[nz][nx][ny]&&a[nz][nx][ny])
            {
                q.push({nz,nx,ny});
                cnt++;
                vis[nz][nx][ny]=true;
            }
        }
    }
    return cnt;
}



int main()
{
    scanf("%d%d%d%d", &m,&n,&l,&T);

    for(int i=0;i<l;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    int ans=0;
    for(int i=0;i<l;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(a[i][j][k]&&!vis[i][j][k])
                {
                    int t =bfs(i,j,k);
                    if(t>=T) 
                    {
                        ans+=t;
                    }
                }

            }
        }
    }
    printf("%d\n",ans);

    return 0;
}