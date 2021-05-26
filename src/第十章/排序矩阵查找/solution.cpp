#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++)
        {
            int j = matrix[i].size()-1;
            while(j>=0 && matrix[i][j]>target) j--;
            if(j >= 0 && matrix[i][j] == target) return true;
        }
        return false;
    }
};