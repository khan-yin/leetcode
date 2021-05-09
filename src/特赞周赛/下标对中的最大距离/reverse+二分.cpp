#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        reverse(nums2.begin(),nums2.end());
        int len = 0;
        int n = nums2.size();
        for(int i=0;i<nums1.size();i++)
        {
            int j = 0;
            int jmin = lower_bound(nums2.begin(),nums2.end(),nums1[i]) - nums2.begin();
            if(jmin!=n)
                len = max(len,n-1-jmin-i);
            // cout<<i<<" "<<j<<endl;
            
        }
        return len;
    }
};