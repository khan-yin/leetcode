#include<vector>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> res;
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0||k==0)
            return res;
        deque<int> dq;
        for(int i=0;i<k;i++)
        {
            while(!dq.empty()&&nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
        }

        res.push_back(nums[dq.front()]);

        for(int i=k;i<n;i++)
        {
            while(!dq.empty()&&nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);

            while(dq.front()<=i-k)
                dq.pop_front();
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};