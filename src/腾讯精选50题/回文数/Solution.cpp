#include<string>
#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        string s=to_string(x);
        // cout<<s;
        int i=0;
        int j=s.length()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};