#include<set>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<60;j++)
            {
                if(cnt(i)+cnt(j)==turnedOn)
                {
                    res.push_back(to_string(i)+":"+(j < 10 ? "0"+to_string(j) : to_string(j)));
                }
            }
        }
        return res;
    }

    int cnt(int x)
    {
        int c= 0;
        while(x!=0)
        {
            x -= (x & -x);
            c++;
        }
        return c;
    }
};