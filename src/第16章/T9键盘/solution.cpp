#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> getValidT9Words(string num, vector<string>& words) {
        char map[26] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','7','8','8','8','9','9','9','9'};
        vector<string> res;
        for(string w : words)
        {
            string s="";
            for(char i : w)
            {
                s+=map[i-'a'];
            }
            if(s==num) res.push_back(w);
        }
        return res;
    }
};