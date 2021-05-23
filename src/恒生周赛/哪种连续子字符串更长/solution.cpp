#include<string>
using namespace std;

class Solution {
public:
    bool checkZeroOnes(string s) {  
        int len1=0;
        int len0=0;
        int i=0;
        while(i<s.size())
        {
            int l=1;
            int j=i+1;
            while(j<s.size())
            {
                if(s[j]==s[i]) l++;
                else break;
                j++;
            }
            if(s[i]=='0') len0 = max(len0,l);
            else len1= max(len1,l);
            i = j;
        }
        // cout<<len1<<" "<<len0<<endl;
        return len1>len0;
    }
};