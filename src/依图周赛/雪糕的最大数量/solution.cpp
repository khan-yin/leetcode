#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int cnt=0;
        for(int i=0;i<costs.size()&&coins>0;i++)
        {
            if(coins<costs[i])
                break;
            coins-=costs[i];
            cnt++;
        }
        return cnt;
    }
};