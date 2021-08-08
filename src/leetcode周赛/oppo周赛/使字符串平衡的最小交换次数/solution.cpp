#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0;
        int res = 0;
        for(auto& x : s)
        {
            if(x=='[') cnt++;
            else
            {
                cnt--;
                if(cnt<0) 
                {
                    cnt+=2;
                    res++;
                }
            }
        }
        return res;
    }
};