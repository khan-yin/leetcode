#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

class Solution {
public:
    int cutBar(int n, int m) {
        int slices = 1;
        int cnt = 0;
        while (slices < n) {
            ++cnt;
            slices += min(slices, m);
        }
        return cnt;
    }
};
