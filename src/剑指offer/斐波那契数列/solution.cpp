#include<iostream>
using namespace std;

class Solution {
public:
    int num[101];
public:
    int fib(int n) {
        if(n==0||n==1)
            return n;
        num[0]=0;
        num[1]=1;
        for(int i=2;i<=n;i++)
        {
            num[i]= num[i-1] % 1000000007 + num[i-2] % 1000000007;
        }
        return num[n] % 1000000007;
    }
};