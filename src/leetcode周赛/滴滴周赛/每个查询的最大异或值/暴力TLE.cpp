#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int maxk = (int)(pow(2,maximumBit));
        vector<int> presum(nums.size());
        vector<int> res(nums.size());
        presum[0]=nums[0];
        for(int i=1;i<nums.size();i++)
            presum[i]=nums[i]^presum[i-1];
        
        // cout<<(0^3)<<" "<<(0^2)<<" "<<(0^1)<<" "<<endl;
        // for(int i=0;i<nums.size();i++)
        //     cout<<presum[i]<<" ";
        // cout<<endl;
        
        for(int i=0;i<nums.size();i++)
        {
            for(int k=maxk-1;k>=0;k--)
            {
                // cout<<res[i]<<" "<<k<<" "<<(presum[i]^res[i])<<" "<<(presum[i]^k)<<endl;
                if((presum[i]^res[i])<(presum[i]^k))
                    res[i]=k;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};