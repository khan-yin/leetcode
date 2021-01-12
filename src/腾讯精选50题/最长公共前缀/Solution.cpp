#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        int start=0;
        int end=start;
        while(end<strs[0].size())
        {
            for(int i=0;i<strs.size();i++)
            {
                if(end>strs[i].size())
                    return strs[i].substr(start,end-start);
                char p=strs[0][end];
                if(p!=strs[i][end])
                    return strs[i].substr(start,end-start);
            }
            end++;
        }

        return strs[0].substr(start,end-start);
        
    }
};