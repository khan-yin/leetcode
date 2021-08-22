#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int gcd(int a,int b)
    {
        if(b==0) return a;
        return gcd(b,a%b);
    }
    int findGCD(vector<int>& nums) {
        int minm=1010,maxm=-1;
        for(int i : nums)
        {
            maxm = max(maxm,i);
            minm = min(minm,i);
        }
        return gcd(maxm,minm);
    }
};