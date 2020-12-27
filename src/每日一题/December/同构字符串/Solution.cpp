#include<unordered_map>
#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length())
            return false;
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for(int i=0;i<s.length();i++)
        {
            char x=s[i];
            char y=t[i];
            if((s2t.count(x)&&s2t[x]!=y)||(t2s.count(y)&&t2s[y]!=x))
                return false;
            s2t[x]=y;
            t2s[y]=x;
        }

        return true;
    }
};