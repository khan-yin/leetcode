#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int> >& matrix, int target) {

        int i=matrix.size()-1;
        int j=0;
        while(i>=0&&j<matrix[0].size())
        {
            if(matrix[i][j]>target) i--;
            else if(matrix[i][j]<target) j++;
            else return true;
        }
        return false;
    }
};