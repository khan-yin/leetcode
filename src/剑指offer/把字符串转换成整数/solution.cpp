#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

class Solution {
public:
    int strToInt(string s) {
        long long f=1;
        long long res=0;
        bool flag=true;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' '&&!flag)
                break;
            if(s[i]!=' '&&!isdigit(s[i]))
            {
                if(!flag)
                    break;
                if(s[i]=='-')
                {
                    f=-1;
                    flag=false;
                }
                else if(s[i]=='+')
                {
                    flag=false;
                }
                else
                    return 0;
            }
            else if(s[i]>='0'&&s[i]<='9')
            {
                res=res*10+(s[i]-'0');
                flag=false;
                if(res>INT_MAX)
                    return f>0?INT_MAX:INT_MIN;
            }
        }
        res = f*res;
        return (int) res;
    }
};