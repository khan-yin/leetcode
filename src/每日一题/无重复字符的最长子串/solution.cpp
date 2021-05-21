#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int hash[128]={0};
        int i=0,j=0;
        int res=0;
        while(i<n)
        {
            while(j<n&&hash[s[j]]<1) ++hash[s[j++]];
            res = max(res,j-i);
            // cout<<i<<" "<<s[i]<<" hash:"<<hash[s[i]]<<" "<<j<<" "<<s[j]<<" hash:"<<hash[s[j]]<<endl;
            //退出循环的下标对应元素就是重复元素
            while(i<n&&s[i]!=s[j]) --hash[s[i++]];
            --hash[s[i++]];
        }
        return res;
    }
};