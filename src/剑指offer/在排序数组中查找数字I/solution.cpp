#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int end = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        return end-start;
    }
};