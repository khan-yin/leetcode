#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
    int  dp[40005];
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        if(len<=1)
            return len;
        
        dp[0]=1;
        int res=0;
        for(int j=1;j<s.size();j++)
        {
            int i=j-1;//向前遍历找s[i]=s[j]的位置
            while(i>=0&&s[i]!=s[j])
                i--;
            dp[j] = dp[j-1]>=(j-i)? j-i:dp[j-1]+1;
            res = max(res,dp[j]);
        }
        return res;
    }
};