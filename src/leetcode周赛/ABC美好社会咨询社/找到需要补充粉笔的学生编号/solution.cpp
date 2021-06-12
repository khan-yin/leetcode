#include<vector>
using namespace std;
class Solution{
public:
    int chalkReplacer(vector<int>& chalk, int k)
    {
        int n = chalk.size();
        vector<long long> t(n);
        t[0] = chalk[0];
        for (int i = 1; i < n; i++)
            t[i] = t[i-1] + chalk[i];
        k -= k / t[n-1] * t[n-1];
        for (int i = 0; i < n; i++)
            if (t[i] > k)
                return i;
        return 0;
    }
};
