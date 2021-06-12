#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i=left;i<=right;i++)
        {
            bool flag = false;
            for(auto item : ranges)
            {
                if(item[0]<=i&&i<=item[1]) flag=true;
            }
            if(!flag) return flag;
        }
        return true;
    }
};