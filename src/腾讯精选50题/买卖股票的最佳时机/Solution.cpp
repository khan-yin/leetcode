#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int inf=1e9;
        int minprice=inf;
        int maxprofit=0;
        for(int price : prices)
        {
            minprice=min(price,minprice);
            maxprofit=max(price-minprice,maxprofit);
        }
        return maxprofit;
    }
};