#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        sort(logs.begin(),logs.end(),[](vector<int> & a,vector<int> &b){
           return a[0]<=b[0]; 
        });
        int res = 0;
        int my = 0;
        for(int i=0;i<logs.size();i++)
        {
            int cnt=1;
            int newtime = logs[i][0];
            for(int j=0;j<i;j++)
            { 
                if(logs[j][0]<=logs[i][0] && logs[j][1]>logs[i][0])
                {
                    cnt++;
                }
            }
            if(cnt>res)
            {
                my = newtime;
                res = cnt;
            }
        }
        return my;
    }
};