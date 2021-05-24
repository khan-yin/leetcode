#include<queue>
#include<vector>
using namespace std;


class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
            priority_queue<int,vector<int>,greater<int> > q;
            vector<int> res;
            for(auto i : arr) 
            {
                q.push(i);
            }
            while(res.size()<k)
            {
                res.push_back(q.top());
                q.pop();
            }
            return res;
    }
};