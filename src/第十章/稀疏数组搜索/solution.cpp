#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int findString(vector<string>& words, string s) {
        unordered_map<string,int> m;
        for(int i = 0;i<words.size();i++)
        {
            if(words[i]!="") m[words[i]]=i;
        }
        if(m.count(s)) return m[s];
        return -1;
    }
};