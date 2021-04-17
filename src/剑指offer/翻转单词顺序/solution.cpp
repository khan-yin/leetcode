#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string str="";
        int i=0;        
        int len = s.size();
        i = len-1;
        bool flag=true;
        while(i>=0)
        {
            while(i>=0&&s[i]==' ')
                i--;
            if(i<0)
                break;
            string tmp="";
            int j=i;
            while(j>=0&&s[j]!=' ')
            {
                // cout<<s[j]<<endl;
                tmp=s[j]+tmp;
                j--;
            }
            // cout<<tmp<<endl;
            if(flag)
            {
                str+=tmp;
                flag=false;
            }
            else
            {
                str=str+' '+tmp;
            }
            i = j-1;
        }
        return str;
    }
};