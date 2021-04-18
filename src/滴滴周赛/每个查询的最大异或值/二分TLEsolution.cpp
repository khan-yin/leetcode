#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    
    
    int dfs(int left,int right,int presum)
    {
        if(left>=right)
        {
            return presum^left;
        }
        int mid = left +  (right-left)/ 2;
        int my = presum^mid;
        int lsum =dfs(left,mid,presum);
        int rsum =dfs(mid+1,right,presum);
        return max(max(lsum,rsum),my);
    }
    
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
            int mk = dfs(0,maxk-1,presum[i]);
            res[i] = mk^presum[i];
            // for(int k=maxk-1;k>=0;k--)
            // {
            //     if((presum[i]^res[i])<(presum[i]^k))
            //         res[i]=k;
            // }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};