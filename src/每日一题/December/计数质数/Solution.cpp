#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);//假设都是质数
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if((long long)i*i<n)
                {
                    for(int j=i*i;j<n;j+=i)
                    {
                        isPrime[j]=0;
                    }
                }
            }
        }
        return ans;
    }
};