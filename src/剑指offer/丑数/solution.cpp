#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long> > q;
        int factors[3]={2,3,5};
        set<long> s;
        q.push(1);
        s.insert(1);
        int res=0;
        for(int i=0;i<n;i++)
        {
            long t = q.top();
            q.pop();
            res = (int) t;
            for(int i=0;i<3;i++)
            {
                long f=factors[i]*t;
                if(!s.count(f))
                {
                    q.push(f);
                    s.insert(f);
                }
            }
        }
        return res;
    }
};