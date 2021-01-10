#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1=nums1.size();
        int length2=nums2.size();
        if(length1+length2==0)
            return 0;
        int i=0;
        int j=0;
        vector<int> nums;
        while(i<length1&&j<length2)
        {
            if(nums1[i]<=nums2[j])
            {
                nums.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i<length1)
        {
            nums.push_back(nums1[i]);
            i++;
        }

        while(j<length2)
        {
            nums.push_back(nums2[j]);
            j++;
        }
        int mid=nums.size()/2;
        if(nums.size()%2==0)
        {
            return (nums[mid-1]+nums[mid])*1.0/2;
        }
        else
            return nums[mid];
    }
};