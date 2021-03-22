#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;


class Solution {
public:
    int dx[5] = {0,-1,1,0,0};
    int dy[5] = {0,0,0,-1,1};
    bool isvisited[205][205];
    vector<vector<char> > board;
    string w;
    int row;
    int column;
    bool dfs(int x,int y,int step)
    {
        if(x<0||x>=this->row||y<0||y>=this->column||this->board[x][y]!=this->w[step]||this->isvisited[x][y])
            return false;
        
        if(step==this->w.size()-1)
            return true;
        this->isvisited[x][y]=true;
        bool flag = dfs(x+dx[1],y+dy[1],step+1) || dfs(x+dx[2],y+dy[2],step+1) ||  dfs(x+dx[3],y+dy[3],step+1) || dfs(x+dx[4],y+dy[4],step+1);
        this->isvisited[x][y]=false;
        return flag;
    }
    

    bool exist(vector<vector<char> >& board, string word) {
        this->row = board.size();
        this->column = board[0].size();
        this->board = board;
        this->w = word;
        for(int i=0;i<this->row;i++)
        {
            for(int j=0;j<this->column;j++)
            {
                bool flag = dfs(i,j,0);
                if (flag) return flag;
            }
        }
            
        return false;
    }
};