#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int find(int j,int x,vector<int>& nums)
    {
        int l = j+1;
        int r = nums.size()-1;
        while(l<r)
        {
            int mid = l + r + 1 >> 1;
            if(nums[mid]<x) l = mid;
            else r = mid - 1;
        }
        return l;
    }
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int res = 0;
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int len = nums[i] + nums[j];
                int it = find(j,len,nums);
                if(nums[it]<len) res += (it - j);
                
            }
        }
        return res;
    }
};