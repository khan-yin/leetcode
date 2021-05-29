#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:

    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for(int i=0;i<nums1.size();i++) res+=(nums1[i]^nums2[i]);
        
        vector<int> nums3 = nums2;
        sort(nums2.begin(),nums2.end());
        if(nums1.size()==1) return nums1[0]^nums2[0];
        while(next_permutation(nums2.begin(),nums2.end()))
        {
            int sum=0;
            for(int i=0;i<nums1.size();i++) sum+=(nums1[i]^nums2[i]);
            res = min(res,sum);
        }
        
        sort(nums1.begin(),nums1.end());
        
        while(next_permutation(nums1.begin(),nums1.end()))
        {
            int sum=0;
            for(int i=0;i<nums1.size();i++) sum+=(nums1[i]^nums3[i]);
            res = min(res,sum);
        }
        
        
        
        return (int)res;
    }
};