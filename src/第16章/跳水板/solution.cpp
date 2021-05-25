#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        set<int> s;
        if(k==0) return res;
        for(int i=0;i<=k;i++)
        {
            s.insert(shorter*i+longer*(k-i));
        }
        for(auto i : s)
            res.push_back(i);
        return res;
    }
};