#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool vis[5010];
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            memset(vis,0,sizeof vis);
            int j = i;
            int cnt=0;
            while(cnt<n)
            {
                vis[j]=true;
                cnt++;
                int step = nums[j];
                step %=n;
                int next = (j + step + n) % n;
                if(nums[j] * nums[next] < 0 ) break; 
                // cout<<j<<"+"<<step<<"->"<<next<<endl;
                if(vis[next]) 
                {
                    if(j == next) break;
                    return true;
                }
                j = next;
            }
        }
        return false;
    }
};