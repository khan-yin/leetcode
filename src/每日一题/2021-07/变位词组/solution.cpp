#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(string item : strs)
        {
            string t = item;
            sort(t.begin(),t.end());
            m[t].push_back(item);
        }
        vector<vector<string>> res;
        for (auto it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res;
    }
};