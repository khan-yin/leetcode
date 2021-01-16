#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=nums1.size()-1;
        m--;
        n--;
        while(n>=0)
        {
            while(m>=0&&nums1[m]>nums2[n])
            {
                swap(nums1[i--],nums1[m--]);
            }
            swap(nums2[n--],nums1[i--]);
        }
    }
};