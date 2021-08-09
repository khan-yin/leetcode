#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(int x,vector<int>& primes)
    {
        int n = primes.size();
        for(int i=0;i<n&&primes[i]<=x;i++)
        {
            while(x%primes[i]==0) x/=primes[i];
        }
        if(x>1) return false;
        return true;
    }
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int cnt=0;
        int num=1;
        while(cnt<n)
        {
            if(check(num,primes)) 
            {
                cnt++;
            }
            if(cnt==n) break;
            num++;
        }
        return num;
    }
};