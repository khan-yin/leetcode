#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        vector<int> num;
        while(n) num.push_back(n%10), n/=10;
        int res = 0;
        for(int i=num.size()-1;i>=0;i--)
        {
            int d = num[i];
            int left=0,right=0,power=1;
            for(int j=num.size()-1;j>i;j--) left = left * 10 + num[j];
            for(int j=i-1;j>=0;j--) right = right * 10 + num[j], power*=10;

            if(d==0) res += left*power;
            else if(d==1) res += left*power + right + 1;
            else res += (left+1) * power;
        }
        return res;
    }
};