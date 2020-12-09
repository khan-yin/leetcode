#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //dp解法
    int uniquePaths_dp(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0||j==0)//只有一行或者一列的时候只有一种走法
                    dp[i][j]=1;
                else
                    dp[i][j]=dp[i][j-1]+dp[i-1][j];//其实就是计算从起点到终点上面和右边的节点走法，最后一步是仅有一种走法，所以到终点的走法就等于这两部分的和
            }
        }
        return dp[m-1][n-1];
    }
    //风格更优雅，组合数
    int uniquePaths_better(int m, int n){
    long long sum = m + n - 2;
    int min = fmin(m - 1, n - 1);
    long long ret = 1;
    long long ins = 1;
    for(int i = 0; i < min ; i++){
        ret *= sum - i;
        ins *= min - i;
    }
    return ret / ins;
    }

    int uniquePaths(int m, int n) {
        long long total=m+n-2;
        long long fenzi=1;
        long long fenmu=1;
        int minn=min(m-1,n-1);
        for(int i=minn;i>0;i--)
        {
            fenzi*=total;
            fenmu*=i;
            total--;
        }
        // cout<<fenzi<<endl;
        // cout<<fenmu<<endl;
        return  (int)(fenzi/fenmu);
    }
};