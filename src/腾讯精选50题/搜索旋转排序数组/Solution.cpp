#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        int left=0;
        int right=len-1;
        if(len==0) 
            return -1;
        else if(len==1)
            return nums[0]==target? 0:-1;
        while(left<=right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            if(nums[0]<=nums[mid])
            {
                if(nums[0]<=target&&target<nums[mid])
                    right=mid-1;
                else
                    left=mid+1;
            }
            else
            {
                if(nums[mid]<target&&target<=nums[len-1])
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;

    }
};
