#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class FindSumPairs {
public:
    vector<int> a,b;
    unordered_map<int,int> cnt;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        a = nums1,b=nums2;
        for(auto x:b) cnt[x]++;
    }
    
    void add(int index, int val) {
        cnt[b[index]]--;
        b[index]+=val;
        cnt[b[index]]++;
    }
    
    int count(int tot) {
       int res = 0;
        for (auto x: a)
            res += cnt[tot - x];
        return res;
    }
};
