#include <iostream>
#include <cstring>
#include <algorithm>
#include<string>
#include <unordered_map>

using namespace std;


char to_lower(char c)
{
    if(c>='A' && c<='Z') c += 32;
    return c;
}

bool check(char c)
{
    if(c>='A'&&c<='Z' || c>='a'&&c<='z' || c>='0'&&c<='9') return true;
    else return false;
}

unordered_map<string,int> mp;

int main()
{
    int cnt=0;
    string res;
    string a;
    
    getline(cin,a);//获取有空格的字符串使用getline
    
    int i=0,j=0;
    for(int i=0;i<a.size();i++)
    {
        j = i;
        string word;
        while(check(a[j])&&j<a.size())
        {
            word+=to_lower(a[j++]);
        }
        
        if(word.size())
        {
            // cout<<word<<endl;
            mp[word]++;
        }
        i = j;
        if(res.empty() || mp[word] > cnt || mp[word]==cnt&&word<res)
        {
            res = word;
            cnt = mp[word];
        }
    }
    cout<<res<<" "<<cnt<<endl;
    return 0;
}