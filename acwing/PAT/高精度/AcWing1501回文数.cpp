// PAT甲级真题1024
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

bool check(vector<int> &a)
{
    for(int i=0,j=a.size()-1;i<j;i++,j--)
    {
        if(a[i]!=a[j]) return false;
    }
    return true;
}



vector<int> add(vector<int> &a,vector<int> &b)
{
    vector<int> c;
    int t=0;
    for(int i=0;i<a.size() || i<b.size() || t;i++)
    {
        int s = t;
        if (i < a.size()) s += a[i];
        if (i < b.size()) s += b[i];
        c.push_back(s % 10);
        t = s / 10;
    }
    return c;
}

int main()
{
    string s;
    int k;
    vector<int> t;
    cin>>s>>k;
    int cnt=0;
    
    for (int i = s.size() - 1; i >= 0; i -- ) t.push_back(s[i] - '0');
    
    // cout<<k<<endl;
    if(!check(t))
    {
        // cout<<1<<endl;
        while(cnt<k)
        {
            vector<int> r(t.rbegin(),t.rend());
            t = add(t,r);
            cnt++;
            if (check(t)) break;
        }
        
    }
    
    
    for(int i=t.size()-1;i>=0;i--) cout<<t[i];
    cout<<endl<<cnt;
    
    return 0;
}
