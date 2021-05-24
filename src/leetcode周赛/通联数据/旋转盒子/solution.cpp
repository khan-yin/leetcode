#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size();
        int m = box[0].size();
        vector<vector<char>> rbox(m, vector<char>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=n-1;j>=0;j--)
            {
                rbox[i][n-1-j] = box[j][i];
                // cout<<rbox[i][n-1-j] << "";
            }
            // cout<<endl;
        }
        
        for(int i=m-2;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                int k = i;
                while(k<m-1&&rbox[k][j] =='#' && rbox[k+1][j] =='.')
                {
                    rbox[k+1][j] = rbox[k][j];
                    rbox[k][j] = '.';
                    k++;
                }
            }
        }
        
        
        return rbox;
    }
};