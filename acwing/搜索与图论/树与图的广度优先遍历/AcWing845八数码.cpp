#include <iostream>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 10;

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int bfs(string start)
{
    string end = "12345678x";
    
    queue<string> q;
    unordered_map<string,int> dis; //存储状态以及相对start的移动次数(距离)
    
    q.push(start);
    dis[start]=0;
    
    while(!q.empty())
    {
        string state = q.front();
        q.pop();
        int distance = dis[state];
        if(state==end) return distance;
        
        int k = state.find('x');//查找x的下标
        int x = k/3, y=k%3; //一维转二维坐标
        
        for(int i=0;i<4;i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if(nextX>=0&&nextX<3&&nextY>=0&&nextY<3)
            {
                swap(state[k], state[nextX * 3 + nextY]); // 二维坐标转一维，并交换
                if(!dis.count(state))//如果状态不存在，则加入新状态，并更新移动次数
                {
                    dis[state] = distance + 1;
                    q.push(state);
                }
                swap(state[k], state[nextX * 3 + nextY]);//恢复现场
            }
        }
    }
    return -1;
    
}

int main()
{
    string start="";
    for (int i = 0; i < 9; i ++ )
    {
        char c;
        cin>>c;
        start+=c;
    }
    
    cout<<bfs(start)<<endl;
    
    return 0;
}