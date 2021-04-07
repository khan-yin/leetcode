#include<queue>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> q;
        for(int i=0;i<k;i++)
        {
            q.emplace(nums[i],i);// value ,index
        }

        vector<int> ans = {q.top().first};

        for(int i=k;i<n;i++)
        {
            q.emplace(nums[i], i);//update queue
            while(q.top().second<=i-k)//index is out of window
            {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};