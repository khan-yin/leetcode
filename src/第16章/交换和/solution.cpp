#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        vector<int> res;
        int sum1 = 0;
        int sum2 = 0;
        for(auto i : array1) sum1 += i;
        for(auto i : array2) sum2 += i;
        sort(array1.begin(),array1.end());
        sort(array2.begin(),array2.end());
        
        for(int i = 0; i<array1.size();i++)
        {
            double k = (sum2 - sum1 + 2*array1[i])*1.0 / 2;
            int t = (int)k;
            if(t*1.0!=k) continue;
            // cout<<binary_search(array2.begin(),array2.end(),t)<<endl;
            if(binary_search(array2.begin(),array2.end(),t))
            {
                res.push_back(array1[i]);
                res.push_back(t);
                return res;
            }
        }
        return res;
    }
};