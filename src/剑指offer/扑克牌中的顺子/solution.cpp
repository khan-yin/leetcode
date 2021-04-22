#include<vector>
#include<set>
#include<iostream>
using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        set<int> s;
        for(int i:nums)
        {
            if(s.find(i)!=s.end())
                return 0;
            if(i>0)
                s.insert(i);
        }
        return *s.rbegin()-*s.begin()<5;
    }
};