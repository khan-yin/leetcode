#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    struct Query
    {
        int index; // 存储原查询的数组下标，因为返回时是需要按原查询次序返回结果
        int preferred;
        int minsize;
        bool operator< (const Query & b) const {
            return minsize < b.minsize;
        }
    };

    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<Query> q;
        int n = queries.size();//查询次数
        for(int i=0;i<n;i++)
            q.push_back({i,queries[i][0],queries[i][1]});

        // 对Query按照minsize排序
        sort(q.begin(),q.end());
        // 对rooms排序也按照size排序
        sort(rooms.begin(),rooms.end(), [](vector<int> &a,vector<int> &b){
            return a[1] < b[1];
        });

        vector<int> res(n);
        const int INF=1e9;
        set<int> S{-INF,INF}; // 取边界位置 set是平衡树结构，复杂度为logn

        // 这里倒过来插入就不需要每次查询完清空集合，因为倒过了查询的minsize是越来越小的，即rooms的数量只会由少变多
        for(int i=n-1,j=rooms.size()-1;i>=0;i--)
        {
            int index = q[i].index, preferred = q[i].preferred, minsize = q[i].minsize;
            // cout<<index<<" "<<preferred<<" "<<minsize<<endl;
            while(j>=0&&rooms[j][1]>=minsize) S.insert(rooms[j--][0]);//插入满足条件的roomid
            
            //要求abs(id - preferred)最小也就是最接近preferred值故采用二分
            // [ *down, prefferred, *up]
            auto up = S.lower_bound(preferred);//返回第一个>=preferred的位置的迭代器
            auto down = up; 
            down--; // 即最大的<preferred的位置迭代器

            if( preferred - *down <= *up - preferred)  res[index] = *down;
            else res[index] = *up;
            
            //说明取到了边界，说明无解
            if(abs(res[index])==INF) res[index] = -1;
        }
        return res;
    }
};