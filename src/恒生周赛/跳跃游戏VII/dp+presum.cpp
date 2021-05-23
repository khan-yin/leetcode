#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n =s.size();
        vector<int> dp(n+1),presum(n+1);//记录方案数
        //presum[i]表示前i位置上总共有多少到达的位置
        dp[1]=1;
        presum[1]=1;
        for(int i=2;i<=n;i++)
        {
            if(s[i-1]=='0')
            {
                int l = max(1,i-maxJump), r = i - minJump;
                if(r>=l&&presum[r]>presum[l-1]) dp[i]=1;
            }
            presum[i] = presum[i-1] + dp[i];
        }
        
        return dp[n];
    }
};