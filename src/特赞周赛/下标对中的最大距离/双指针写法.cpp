#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int len = 0;
        
        for(int i=nums1.size()-1,j = nums2.size()-1;i>=0;i--)
        {
            while(j>=i && nums1[i] > nums2[j]) j--;
            // cout<<i<<" "<<j<<endl;
            len = max(len,j-i);
        }
       
        return len;
    }
};


class Solution2 {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        for (int j = nums2.size() - 1, i = nums1.size() - 1; j >= 0; j -- ) {
            while (i && nums1[i - 1] <= nums2[j]) i -- ;
            if (nums1[i] <= nums2[j]) res = max(res, j - i);
        }
        return res;
    }
};