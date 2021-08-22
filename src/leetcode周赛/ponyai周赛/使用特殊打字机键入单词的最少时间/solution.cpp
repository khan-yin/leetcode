#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
class Solution {
public:
    int minTimeToType(string word) {
        string s = "abcdefghijklmnopqrstuvwxyz";
        int n = 26;
        int temp = 0;
        int res = word.size();
        for(char item : word)
        {
            int t = item - 'a';
            int step = abs(t-temp);
            res += min(step,26-step);
            temp = t;
        }
        return res;
    }
};