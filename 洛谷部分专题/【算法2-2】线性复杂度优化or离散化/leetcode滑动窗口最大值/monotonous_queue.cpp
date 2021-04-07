#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // record the index of maxvalue

        for(int i=0;i<k;i++)
        {
            while(!dq.empty()&&nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
        }
        vector<int> res = {nums[dq.front()]};//first maxvalue

        for(int i=k;i<n;i++)
        {
            while(!dq.empty()&&nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            // delete the index out of the sliding window
            while(dq.front()<=i-k)
                dq.pop_front();
            res.push_back(nums[dq.front()]);
        }

        return res;
        
    }
};