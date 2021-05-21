#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int l = 1, r = 2;
        vector<int> res;
        vector<vector<int>> ans;
        while(l<r)
        {
            int sum = (r+l) * (r-l+1) / 2;
            if(sum==target)
            {
                res.clear();
                for(int i=l;i<=r;i++) res.push_back(i);
                ans.push_back(res);
                l++;//不要忘记存储完后左边界更新，否则会死循环
            }
            else if(sum<target)
            {
                r++;
            }
            else if(sum>target)
            {
                l++;
            }
        }
        return ans;
    }
};