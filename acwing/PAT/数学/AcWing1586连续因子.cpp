// PAT甲级真题1096
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> ans;
    for(int i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            vector<int> res;
            int m = n;
            for(int j=i;j<=n/j;j++)
            {
                if(m%j==0)
                {
                    m/=j;
                    res.push_back(j);
                }
                else break;
            }
            if(res.size()>ans.size())
            {
                ans = res;
            }
        }
    }
    if(!ans.size()) ans.push_back(n);
    cout<<ans.size()<<endl;
    if(ans.size())
    {
        cout<<ans[0];
        for(int i=1;i<ans.size();i++) cout<<"*"<<ans[i];
    }
    return 0;
}