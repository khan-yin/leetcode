#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class Solution {
public:
    int strToInt(string s) {
        int i=0;
        long long res=0;
        while(s[i]==' ')
            i++;
        if(i>s.size())
            return 0;
        int sign=1;
        if(s[i]=='-')
            sign=-1;
        if(s[i]=='+'||s[i]=='-')
            i++;
        if(!isdigit(s[i]))
            return 0;
        for(int j=i;j<s.size();j++)
        {
            if(s[j]<'0'||s[j]>'9')
                break;
            res=res*10+(s[j]-'0');
            if(res>INT_MAX)
                return sign>0? INT_MAX:INT_MIN;
        }
        return (int) res*sign;
    }
};