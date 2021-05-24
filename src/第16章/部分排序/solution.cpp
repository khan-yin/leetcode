#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        vector<int> res = array;
        sort(res.begin(),res.end());
        int i = -1;
        int j = -1;
        for(int k=0;k<array.size();k++)
        {
            if (array[k] != res[k]) {
                if (i == -1) {
                    i = k;
                }
                j = k;
            }
        }
        return {i,j};
    }
};