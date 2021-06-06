#include<vector>
using namespace std;

class Solution {
public:
    int n,m;
    int a[20][20],b[20][20],c[20][20],t[20][20];
    bool findRotation(vector<vector<int> >& mat, vector<vector<int>>& target) {
        n=mat.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[i][j]=mat[i][j];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                t[i][j]=target[i][j];
            }
        }
        
        for(int m=0;m<4;m++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    b[j][n-i-1]=a[i][j];
                }
            }
            
            bool flag=true;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(b[i][j]!=t[i][j]) flag= false;
                }
            }
            
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    a[i][j]=b[i][j];
                    // cout<<b[i][j]<<" ";
                }
                // cout<<endl;
            }
            
            if(flag) return true; 
        }
        return false;
    }
};