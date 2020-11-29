#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
using namespace std;

//记忆化搜索
class Solution {
public:
    unordered_map <int, int> f;//计数
    int getCount(int x)
    {
        if(f.find(x)!=f.end()) return f[x];
        if(x==1) return f[x]=0;
        else if(x&1) return f[x]=getCount(3*x+1)+1;
        else return f[x]=getCount(x/2)+1;
    }
    int getKth(int lo, int hi, int k) {
        vector<int> v;//存储下标
        for(int i=lo;i<=hi;i++) v.push_back(i);
        //因为题目求下标
        sort(v.begin(),v.end(),[&](int o1,int o2){
             if (getCount(o1) != getCount(o2)) return getCount(o1) < getCount(o2);
             else return o1 < o2;
        });
        return v[k-1];
    }
};