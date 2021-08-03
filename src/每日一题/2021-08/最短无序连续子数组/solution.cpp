#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> b =nums;
        sort(b.begin(), b.end());
        int i=0,j=b.size()-1;
        while(i<b.size()&&nums[i]==b[i]) i++;
        while(j>=0&&nums[j]==b[j]) j--;
        
        return i<j? j-i+1 : 0;
    }
};