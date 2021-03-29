#include<string>
using namespace std;

class Solution {
public:
    int hash[30];
    char firstUniqChar(string s) {
        
        for(int i=0;i<s.size();i++)
        {
            hash[s[i]-'a']++;
            // cout<<s[i]<<" "<<s[i]-'a'<<endl;
        }

        for(int i=0;i<s.size();i++)
        {
            if(hash[s[i]-'a']==1)
                return s[i];
        }
        return ' ';
    }
};