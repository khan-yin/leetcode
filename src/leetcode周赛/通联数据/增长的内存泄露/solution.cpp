#include<vector>
#include<queue>
#include <iostream>
using namespace std;

struct Memory{
    int m;
    int i;
    bool operator< (const Memory & w) const
    {
        if(m==w.m)
            return i > w.i;
        return m<w.m;
    }
};

class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        priority_queue<Memory> q;
        vector<int> res(3);
        // cout<<memory1<<" "<<memory2<<endl;
        q.push({memory1,1});
        q.push({memory2,2});
        long long sum = (long long)memory1 + (long long)memory2;
        int c=1;
        
//         while(q.size())
//         {
//             int m = q.top().m,i = q.top().i;
//             // cout<<m<<" "<<i<<endl;
//             q.pop();
//         }
        
//         q.push({memory1,1});
//         q.push({memory2,2});
        while(c<= q.top().m)
        {
            int m = q.top().m,i = q.top().i;
            // cout<<m<<" "<<i<<endl;
            sum -= c;
            q.pop();
            q.push({m-c,i});
            c++;
        }
        while(q.size())
        {
            int m = q.top().m,i = q.top().i;
            res[i] = m;
            q.pop();
        }
        res[0] =c;
        return res;
    }
};