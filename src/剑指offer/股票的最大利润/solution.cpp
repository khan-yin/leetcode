#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int maxprofit=0;
        int cost=prices[0];
        for(int i=1;i<prices.size();i++)
        {
            // profit[i]=max( profit[i-1] , price[i]-min(0...price[i]) )
            maxprofit= max(maxprofit,prices[i]-min(cost,prices[i]));
            cost=min(cost,prices[i]);
        }
        return maxprofit;
    }
};