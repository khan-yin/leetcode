#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int n = s.size();
        vector<int> dp(n);//dp[i]表示前i个字符的翻译结果数
        dp[0]=1;

        for(int i=1;i<n;i++)
        {
            dp[i] = dp[i-1];
            int number = (s[i-1]-'0')*10+s[i]-'0';
            if(number>9&&number<26)
            {
                if(i==1) dp[i]++;
                else dp[i] += dp[i-2];
            }
            // cout<<i<<" "<<dp[i]<<endl;
        }

        return dp[n-1];
    }
};