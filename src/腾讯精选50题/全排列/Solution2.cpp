#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > res;
        int len=nums.size();
        res.push_back(nums);
        for(int i=0;i<nums.size();i++)
        {
            int size=res.size();
            for(int j=i+1;j<nums.size();j++)
            {
                for(int k=0;k<size;k++)
                {
                    vector<int> s=res[k];
                    swap(s[i],s[j]);
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};