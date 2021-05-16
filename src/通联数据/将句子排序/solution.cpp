#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        unordered_map<int,string> map;
        string str ="";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                str="";
            }
            else if(isdigit(s[i]))
            {
                // cout<<s[i]<<endl;
                int k = s[i] - '0';
                map[k]=str;
            }
            else
            {
                str +=s[i];
            }
        }
        
        string res ="";
        for(int i=1;i<=map.size();i++)
        {
            if(i>1)
                res+=' ';
            res +=map[i];
           
        }
        
        return res;
    }
};