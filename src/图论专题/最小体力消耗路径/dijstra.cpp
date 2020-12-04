#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct Edge {
    int start, end, dis;
    Edge(int _start, int _end, int _dis): start(_start), end(_end), dis(_dis) {}
    bool operator< (const Edge& that) const {
        return dis > that.dis;
    }
};

class Solution {
private:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    int h;
    int w;
public:
    //单源最短路问题
    int minimumEffortPath(vector<vector<int>>& heights) {
        this->h=heights.size();
        this->w=heights[0].size();
        vector<int> dist(h*w);
        vector<bool> isvisted(h*w);
        priority_queue<Edge> q;
        q.emplace(0,0,0);
        dist[0]=0;
        while(!q.empty())
        {
            auto tempEdge=q.top();
            int start=tempEdge.start;
            int end=tempEdge.end;
            int dis=tempEdge.dis;

            q.pop();
            if(isvisted[start*w+end])//该节点已被访问则跳过
                continue;

            isvisted[start*w+end]=true;
            dist[start*w+end]=dis;
            for(int i=0;i<4;i++)
            {
                int nx=start+dx[i];
                int ny=end+dy[i];
                if(nx<0||nx>=h||ny<0||ny>=w||isvisted[nx*w+ny])
                    continue;
                int minus=abs(heights[start][end]-heights[nx][ny]);
                dist[nx*w+ny]=max(minus,dis);
                q.emplace(nx,ny,dist[nx*w+ny]);
            }
        }
        return dist[h * w - 1];
    }
};

