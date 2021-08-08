#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        vector<string> res;
        string t;
        for(auto item : words)
        {
            t+=item;
            res.push_back(t);
        }
        for(string item : res)
        {
            if(item == s) return true;
        }
        return false;
    }
};