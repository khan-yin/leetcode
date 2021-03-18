#include<iostream>
#include<cstdio>
using namespace std;

class Solution {
public:
    int numWays(int n) {
        int a=1;
        int b=1;
        int sum=1;
        for(int i=2;i<=n;i++)
        {
            sum = (a+b)%1000000007;
            a = b;
            b = sum;
        }
        return sum % 1000000007;
    }
};