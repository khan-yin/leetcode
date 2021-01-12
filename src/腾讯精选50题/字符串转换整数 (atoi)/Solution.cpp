#include<string>
#include<iostream>
#include<cstdio>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int i = 0;
        int flag = 1;
        while (str[i]==' ')
        {
            i++;
        }
        if (str[i]== '-') { flag=-1; }
        if(str[i]== '+'|| str[i] == '-')
        {
            i++;
        }
        while (i < str.size() && isdigit(str[i]))
        {
            int pop = str[i] - '0';
            if (res > INT_MAX/10 ||(res== INT_MAX/10&&pop>7))
            {
                return flag >0?INT_MAX : INT_MIN;
            }
            res = res*10+pop;
            i++;
        }
        return flag >0? res :-res;
    }
};
