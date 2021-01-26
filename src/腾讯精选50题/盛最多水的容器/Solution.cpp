#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        double area = 0;
        while(left<right)
        {
            double temp = min(height[left], height[right]) * (right - left);
            area = max(area, temp);
            if(height[left]<=height[right])
                left++;
            else
                right--;
        }
        return area;
    }
};