#include<string>
#include<iostream>
#include<algorithm>
using namespace std;


class Solution {
public:
    string smallestGoodBase(string n) {
        long long x = stoll(n);
        int max = (int)(log2(x) + 1);
        for(int len = max; len >= 3; len--)
        {
            long long k = (long long)pow(x, 1. / (len - 1));
            long res = 0;
            for (int i = 0; i < len; i++) res = res * k + 1;
            if (res == x) return to_string(k);
        }
        return to_string(x - 1);
    }
};