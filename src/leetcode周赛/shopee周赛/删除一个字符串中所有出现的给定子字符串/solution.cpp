#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    bool check(string s,string part)
    {
        return s.find(part) !=s.npos;
    }
    
    string removeOccurrences(string s, string part) {
        int n = s.size();
        int m = part.size();
        int i = 0,j=0;
        string res ="";
        while(check(s,part))
        {
            int pos = s.find(part);
            s.replace(pos,m,"");
        }
        return s;
    }
};