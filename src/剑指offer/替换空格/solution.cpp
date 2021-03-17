#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string a="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                a+="%20";
            }
            else
                a+=s[i];
        }
        return a;
    }
};