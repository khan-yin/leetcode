#include<string>
using namespace std;


class Solution {
public:
    bool dp[100010];
    bool canReach(string s, int minJump, int maxJump) {
        int n =s.size();
        dp[0]=true;
        for(int i=0;i<n;i++)
        {
            if(s[i]!='0') continue;
            for(int j=minJump;j<=maxJump;j++)
            {
                if(i-j>=0)
                    dp[i] |= dp[i-j];
            }
        }
        return dp[n-1];
    }
};