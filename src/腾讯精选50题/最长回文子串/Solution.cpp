#include<string>
#include<iostream>
#include<cstdio>
using namespace std;

class Solution {

public:
    string longestPalindrome(string s) {
        int len=s.length();
        bool dp[100][100]; //dp[len][len], 表达式必须含有常量值--变量"len"(己声明所在行数:9）的值不可用作常量C/C++(28) 5 bool dp[ len][len];
        string ans="";

        for(int n=0;n<len;n++)
        {
            for(int i=0;i+n<len;i++)
            {
                int j=i+n;
                if(n==0)
                    dp[i][j]=true;
                else if(n==1)
                    dp[i][j]=(s[i]==s[j]);
                else
                    dp[i][j]=(dp[i+1][j-1]&&(s[i]==s[j]));
                if(dp[i][j]&&n+1>ans.length())
                {
                     ans=s.substr(i,n+1);//substr(index,count)
                    //  cout<<ans<<endl;
                }
                   
            }
        }
        return ans;
    }
};