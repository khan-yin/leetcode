#include<vector>
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

class Solution {
public:
    int mahadundist(vector<int>& a,vector<int>& b)
    {
        return abs(a[0]-b[0])+abs(a[1]-b[1]);
    }
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> my={0,0};
        int my_dist = mahadundist(my,target);
        for(vector<int>&p : ghosts)
        {
            if(my_dist>=mahadundist(p,target))
                return false;
        }
        return true;
    }
};