// PAT甲级真题1038
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;


bool cmp(string a,string b)
{
    return a+b < b+a;
}

int main()
{
    int n;
    scanf("%d", &n);
    vector<string> res;
    while (n -- )
    {
        string str;
        cin>>str;
        res.push_back(str);
    }


    sort(res.begin(),res.end(),cmp);
    string ans;
    for(auto item : res)
    {
        ans += item;
    }
    int i=0;
    while(i<ans.size()&&ans[i]=='0') i++;
    if(i==ans.size()) cout<<0;
    else cout<<ans.substr(i);
    return 0;
}