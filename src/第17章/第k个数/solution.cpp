#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int getKthMagicNumber(int k) {
        int* nums = new int[k];
        nums[0] = 1;
        int p3=0;
        int p5=0;
        int p7=0;
        for(int i=1;i<k;i++)
        {
            nums[i] = min(min(nums[p3]*3, nums[p5]*5), nums[p7]*7);
            //去重
            if(nums[i]==nums[p3]*3) p3++;
            if(nums[i]==nums[p5]*5) p5++;
            if(nums[i]==nums[p7]*7) p7++;
        }
        return nums[k-1];
    }
};