#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
public:
    string OR(string s)
    {
        string res;
        for(char i : s) res += (i=='0'?'1':'0');
        return res;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s;
        int n = nums.size();
        string res;
        for(int i=0;i<n;i++) res+='0';
        // cout<<res<<endl;
        for(string i : nums) s.insert(i);
        
        for(auto i : s)
        {
            string si = OR(i);
            if(!s.count(si)) return si;
        }
        
        return res;
    }
};