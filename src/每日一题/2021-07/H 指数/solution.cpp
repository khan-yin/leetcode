#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int h=0;
        int i=citations.size()-1;
        while(i>=0&&citations[i]>h)
        {
            h++;
            i--;
        }
        return h;
    }
};