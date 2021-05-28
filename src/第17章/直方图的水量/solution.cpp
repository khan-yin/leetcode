#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res=0;
        if(!n) return 0;
        vector<int> leftmax(n);
        vector<int> rightmax(n);
        leftmax[0]=height[0];
        for(int i=1;i<height.size();i++)
        {
            leftmax[i] = max(leftmax[i-1],height[i]); 
        }
        rightmax[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmax[i] = max(rightmax[i+1],height[i]); 
        }

        for(int i=0;i<n;i++)
        {
            res += min(leftmax[i],rightmax[i]) - height[i];
        }
        return res;
    }
};