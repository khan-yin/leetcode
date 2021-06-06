#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> m;
        for(int i:nums)
        {
            m[i]++;
        }
        int len=m.size();
        int total=0;
        int pre=0;
        auto e = m.rend();
        e--;
        for(auto iter=m.rbegin();iter!=e;iter++)
        {
            total+=pre;
            total+=iter->second;
            pre+=iter->second;
        }
        
        return total;
    }
};