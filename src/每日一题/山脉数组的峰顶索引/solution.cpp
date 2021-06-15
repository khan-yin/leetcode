#include<vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        while(l<r)
        {
            int mid = l + r >> 1;
            if(arr[mid]>arr[mid+1]) r = mid;
            else l = mid+1;
        }
        return l;
    }
};