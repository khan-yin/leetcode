#include<vector>
#include<iostream>
#include<cstdio>
using namespace std;
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        int sum=0;
        vector<bool> res;
        int c=0;
        for(int i=0;i<A.size();i++)
        {
            // sum = ((sum << 1) + A[i]);溢出
            // cout<<i<<" "<<sum<<endl;
            sum = ((sum << 1) + A[i]) % 5;
            res.push_back(sum==0);
        }
        return res;
    }
};