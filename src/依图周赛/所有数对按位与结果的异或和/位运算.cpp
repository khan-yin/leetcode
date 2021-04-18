#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int t1=0,t2=0;
        for(int i:arr1)
        {
            t1^=i;
        }
        for(int i:arr2)
        {
            t2^=i;
        }
        return (t1&t2);
        // for(int i=0;i<arr1.size();i++)
        // {
        //     for(int j=0;j<arr2.size();j++)
        //     {
        //         if(i==0&&j==0)
        //             continue;
        //         val^=(arr1[i]&arr2[j]);
        //     }
        // }
    }
};