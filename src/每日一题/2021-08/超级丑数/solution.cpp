#include<vector>
#include<queue>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        unordered_set<long long> s;

        priority_queue<long long ,vector<long long>,greater<long long>> q;
        q.push(1);
        // 1 是最小的丑数。
        //对于任意一个丑数x，其与任意给定的质因数primes[i]相乘，结果仍为丑数。
        int res = 0;
        for(int i=0;i<n;i++)
        {
            long long t = q.top();
            q.pop();
            res = (int) t;
            for(auto& item : primes)
            {
                long long p = t * item;
                if(!s.count(p))
                {
                    s.insert(p);
                    q.push(p);
                } 
            }
        }
        return res;

    }
};