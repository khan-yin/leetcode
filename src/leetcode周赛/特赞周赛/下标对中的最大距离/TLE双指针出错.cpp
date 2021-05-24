#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int len = 0;
        
        for(int i=0;i<nums1.size();i++)
        {
            int j = nums2.size()-1;
            while(j>=i && nums1[i] > nums2[j]) j--;
            // cout<<i<<" "<<j<<endl;
            len = max(len,j-i);
        }
        return len;
    }
};