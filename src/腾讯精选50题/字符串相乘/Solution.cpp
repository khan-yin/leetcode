#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0")
            return "0";
        string ans;
        vector<int> a, b, c;
        c.resize(num1.size() + num2.size() - 1);
        for(int i=num1.size()-1; i>=0;i--) a.push_back(num1[i] - '0');
        for(int j=num2.size()-1; j>=0;j--) b.push_back(num2[j] - '0');
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<b.size();j++)
            {
                c[i+j]+=a[i]*b[j];
            }
        }
        int k=0;
        for(int i=0;i<c.size();i++)
        {
            k+=c[i];
            ans=(char)(k%10+'0')+ans;
            k/=10;
        }
        //还剩下最高位进位情况
        while(k)
        {
            ans=(char)(k%10+'0')+ans;
            k/=10;
        }
        return ans;
    }
};