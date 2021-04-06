#include<queue>
#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
public:
    priority_queue<int> q;
    int lastStoneWeight(vector<int>& stones) {
        for(int i=0;i<stones.size();i++)
        {
            q.push(stones[i]);
        }

        while(q.size()>1)
        {
            int y = q.top();
            q.pop();
            int x = q.top();
            q.pop();
            if(x!=y)
            {
                q.push(y-x);
            }
        }
        return q.size()==0?0:q.top();
    }
};