#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;


struct Task {
	int start;
	int cost;
    int number;
    bool operator >(const Task &x) const { 
        if(cost==x.cost)
            return this->start>x.start;
        else
            return this->cost>=x.cost; 
    }
};

bool cmp(vector<int> a,vector<int> b)
{
    return a[0]<b[0];
}

class Solution {
public:
    bool numbers[100006];
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<Task,vector<Task>,greater<Task> > q;
        
        int size=tasks.size();
        vector<int> res;
        int time=0;
        sort(tasks.begin(),tasks.end(),cmp);
        while(res.size()<size)
        {
            for(int i=0;i<tasks.size();i++)
            {
                if(time>=tasks[i][0]&&!numbers[i])
                {
                    // cout<<"pushtime:"<<time<<" "<<tasks[i][0]<<" "<<tasks[i][1]<<" "<<"number:"<<i<<endl;
                    // q.push((Task){tasks[i][0],tasks[i][1],i});
                    numbers[i]=true;
                }
            }
            
            if(q.size()>0)
            {
                Task now = q.top();
                // cout<<"poptime:"<<time<<" "<<now.start<<" "<<now.cost<<" "<<now.number<<endl;
                q.pop();
                now.cost--;
                if(now.cost>0)
                    q.push(now);
                else
                    res.push_back(now.number);
            }
            time++;
        }
        return res;
    }
};