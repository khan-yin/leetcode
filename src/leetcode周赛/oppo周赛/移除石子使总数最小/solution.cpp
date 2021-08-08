#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int,vector<int>> q;
        int sum = 0;
        for(int i : piles)
        {
            q.push(i);
            sum+=i;
        }
        int i=0;
        while(i<k&&q.size())
        {
            int t = q.top();
            q.pop();
            int sub = t/2;
            // cout<<t<<' '<<sub<<endl;
            t -= sub;
            
            sum-=sub;
            i++;
            if(t>0) q.push(t);
        }
        return sum;
    }
};