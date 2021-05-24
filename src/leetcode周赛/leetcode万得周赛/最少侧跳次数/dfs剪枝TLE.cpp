#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int step=-1;
    void dfs(int position,int index,vector<int>& obstacles,int tmpstep)//position 赛道，index是目前的位置
    {
        if(tmpstep>=this->step&&this->step>-1)//剪枝
            return;
        
        if(obstacles[index]==position)
            return;
        cout<<index<<" "<<position<<endl;
        if(index==obstacles.size()-1)
        {
            this->step=  this->step>-1? min(tmpstep,this->step):tmpstep;
            return;
        }
        
        int obp = obstacles[index+1];
        if(obp>0&&obp==position)
        {
            for(int i=1;i<=3;i++)
            {
                if(i==position||i==obstacles[index])
                    continue;
                dfs(i,index+1,obstacles,tmpstep+1);
            }
        }
        //==0
        dfs(position,index+1,obstacles,tmpstep);
    }
    int minSideJumps(vector<int>& obstacles) {
        dfs(2,0,obstacles,0);
        return this->step;
    }
};