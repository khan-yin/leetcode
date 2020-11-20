#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
class Solution {
public:
    int dir_x[8] ={-1,-1,-1, 0, 0, 1, 1, 1};
    int dir_y[8] ={-1, 0, 1,-1, 1,-1, 0, 1};

    void dfs(vector<vector<char>>& board,int row,int column){
        // cout<<row<<" "<<column<<endl;
        int cnt=0;
        for(int i=0;i<8;i++)
        {
            int x=row+dir_x[i];
            int y=column+dir_y[i];
            if(x<0||x>=board.size()||y<0||y>=board[0].size())
            {
                continue;
            }
            cnt+= (board[x][y]=='M');
        }
        if(cnt>0)
        {
            board[row][column]=cnt+'0';
        }
        else{
            board[row][column]='B';
            for(int i=0;i<8;i++)
            {
                int x=row+dir_x[i];
                int y=column+dir_y[i];
                if(x<0||x>=board.size()||y<0||y>=board[0].size()||board[x][y]!='E')
                {
                    continue;
                }
                dfs(board,x,y);
            }
        }
    }

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = click[0];
        int column=click[1];
        if(board[row][column]=='M'){
            board[row][column]='X';
        }else{
            dfs(board,row,column);
        }
        return board;
    }
};