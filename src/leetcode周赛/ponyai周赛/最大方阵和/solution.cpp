#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> fu;
        long long res = 0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                fu.push_back(abs(matrix[i][j]));
                res += abs(matrix[i][j]);
                if(matrix[i][j]<=0) cnt++;
            }
        }
        sort(fu.begin(),fu.end());
        if(cnt&1)
        {
            res -= 2*fu[0];
        }
            
        return res;
    }
};