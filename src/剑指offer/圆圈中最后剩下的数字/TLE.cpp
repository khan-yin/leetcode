#include<vector>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            res.push_back(i);
        }
        int i=0;
        
        while(res.size()>0)
        {
            i=(i+m-1)%res.size();
            res.erase((res.begin()+i));
        }
        return res[0];
    }
};