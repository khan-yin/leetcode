#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    int row;
    int column;
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        row = matrix.size();
        if(row==0)
            return res;
        if(row==1)
            return matrix[0];
        column = matrix[0].size();
        int left = 0;
        int right = column-1;
        int down = row-1;
        int up = 0;
        int step=0;
        while(left<=right&&up<=down)
        {
            if(step%4==0)
            {
                //left up -> right up
                for(int i=left;i<=right;i++)
                    res.push_back(matrix[up][i]);
                up++;
            }
            else if(step%4==1)
            {
                // right up -> right down
                for(int i=up;i<=down;i++)
                    res.push_back(matrix[i][right]);
                right--;
            }
            else if(step%4==2)
            {
                // right down -> left down
                for(int i=right;i>=left;i--)
                    res.push_back(matrix[down][i]);
                down--;
            }
            else if(step%4==3)
            {
                // left down -> left up
                for(int i=down;i>=up;i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
            step++;
        }
        return res; 
    }
};