#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


bool cmp(string& a,string& b)
{
    return a+b < b+a;
}

class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> res;
        for(int i=0;i<nums.size();i++)
        {
            // cout<<to_string(nums[i])<<endl;
            res.push_back(to_string(nums[i]));
        }
        sort(res.begin(),res.end(),cmp);
        string ans="";
        for(int i=0;i<res.size();i++)
            ans+=res[i];
        return ans;
    }
};