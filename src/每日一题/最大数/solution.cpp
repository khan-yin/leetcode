#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool cmp(string &a,string &b)
{
    return a+b>b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> int2str;
        string res;
        for(int i:nums)
        {
            int2str.push_back(to_string(i));
        }

        sort(int2str.begin(),int2str.end(),cmp);
        for(string s:int2str)
        {
            res+=s;
        }
        if(res[0]=='0') 
            return "0";
        return res;
    }
};