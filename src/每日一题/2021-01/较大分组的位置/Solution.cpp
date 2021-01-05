#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        for(int i=0;i<s.size();)
        {
            char p=s[i];
            int j=i+1;
            while(j<s.size())
            {
                if(s[j]==p)
                    j++;
                else
                    break;
            }
            if(j-i>=3)
            {
                vector<int> m;
                m.push_back(i);
                m.push_back(j-1);
                res.push_back(m);
            }
            i=j;
        }
        return res;
    }
};