#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int i = lower_bound(begin(nums), end(nums), target) - begin(nums), j = upper_bound(begin(nums), end(nums), target) - begin(nums);
        if (i == j) return {-1, -1};
        else return {i, j - 1};
    }
};