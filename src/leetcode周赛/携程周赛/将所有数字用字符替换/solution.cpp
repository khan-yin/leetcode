#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string replaceDigits(string s) {
        string res="";
        for(int i=0;i<s.size();i++)
        {
            if(i%2==0) res+=s[i];
            else
            {
                // cout<<s[i-1]<<" "<<(char)(s[i-1]+s[i]-'0')<<" ";
                res+=(char)(s[i-1]+s[i]-'0');
            }
        }
        return res;
    }
};