#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(char x)
    {
        string a = "aeiouAEIOU";
        return a.find(x) != a.npos;
    }
    string reverseVowels(string s) {
        int i =0;
        int n = s.size();
        int j = n-1;
        while(i<j)
        {
            while(i<n&&!check(s[i])) i++;
            while(j>=0&&!check(s[j])) j--;
            if(i<j)
            {
                swap(s[i],s[j]);
                i++;
                j--;
            }
            
            
        }
        return s;
    }
};