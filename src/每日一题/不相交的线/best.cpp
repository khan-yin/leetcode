#include<vector>
using namespace std;

int a[510];
int b[510];
int dp[510][510];//表示a[]前i和b[]前j个位置的最大连线数

//a[i]==b[j], a[i]==b[j-1], a[i-1]==b[j],
// dp[i-1][j-1] + 1 dp[i-1][j-2]+1 dp[i-2][j-1]+1 dp[i-1][j-1]
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        for(int i=0;i<n;i++)
            a[i+1] = nums1[i];
        for(int i=0;i<m;i++)
            b[i+1] = nums2[i]; 
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //求最大可重复不遗漏就行
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                if(a[i]==b[j]) dp[i][j] = max(dp[i][j],dp[i-1][j-1]+1);
                // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        return dp[n][m];
    }
};