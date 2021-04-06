#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> res;
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int> q;
        if(k==0)
            return res;
        for(int i=0;i<arr.size();i++)
        {
            if(q.size()<k)
                q.push(arr[i]);
            else
            {
                if(q.top()>arr[i])
                {
                    q.pop();
                    q.push(arr[i]);
                }
            }
        } 
        // cout<<q.size()<<endl;
        while(!q.empty())
        {
            // cout<<q.top()<<endl;
                res.push_back(q.top());
                q.pop();
        }
        return res;
    }
};