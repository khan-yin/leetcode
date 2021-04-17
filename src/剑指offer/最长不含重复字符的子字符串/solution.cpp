#include<iostream>
#include<string>
#include<cstring>
using namespace std;

class Solution {
public:
    
    int lengthOfLongestSubstring(string s) {
        int a[10000];
        int len=1;
        if(s.size()==0)
            return 0;
        for(int i=0;i<s.size();i++)
        {
            memset(a,0,sizeof(a));
            a[s[i]-' ']++;
            int j=i+1;
            for(;j<s.size();j++)
            {
                // cout<<j<<" "<<s[j]<<"->"<<i<<" "<<s[i]<<endl;
                int ch = s[j]-' ';   
                if(a[ch]>0)
                {
                    break;
                }
                else
                {
                    a[ch]++;
                }
            }
            
            len = max(len,j-i);
            // cout<<"break"<<" "<<len<<endl;
            
        }
        return len;
    }
};