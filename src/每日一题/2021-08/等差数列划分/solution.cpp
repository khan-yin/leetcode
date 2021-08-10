#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int c = 0;
        for(int i=0;i+2<nums.size();i++)
        {
            int d = nums[i+1]-nums[i];
            int j = i;
            while(j+1<nums.size()&&nums[j+1]-nums[j]==d) j++;
            int len = j-i+1;
            // cout<<j<<' '<<i<<' '<<j-i<<endl;
            int a1 = 1, an = len - 3 + 1;
            c +=(a1 + an) *  an /2;
            i = j -1;
        }
        return c;
    }
};