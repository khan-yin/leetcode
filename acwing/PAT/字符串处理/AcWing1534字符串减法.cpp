#include <iostream>
#include <cstring>
#include <algorithm>
#include<cstdio>
#include<string>
#include <unordered_set>

using namespace std;

unordered_set<char> s;//基于平衡树结构，复杂度O(logn)

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);

    string res;

    for(int i=0;i<s2.size();i++)
    {
        s.insert(s2[i]);
    }

    for(int i=0;i<s1.size();i++)
    {
        if(s.count(s1[i])) continue;
        res += s1[i];
    }
    cout<<res<<endl;
    return 0;
}
