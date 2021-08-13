#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 110;

inline bool check(string s)
{
    if(!isalpha(s[0])) return false;
    bool flag=false;
    for(int i=0;i<s.size();i++)
    {
        if(!isdigit(s[i]) && !isalpha(s[i]) ) return false;
        if(isdigit(s[i])) flag=true;
    } 
    return flag;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        string s;
        cin>>s;
        if(check(s)) puts("Accept");
        else puts("Wrong");
    }
    return 0;
}
