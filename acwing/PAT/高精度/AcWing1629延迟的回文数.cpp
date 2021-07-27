// PAT甲级真题1136
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

inline string getnum(vector<int> &a)
{
    string s;
    for(int i=0;i<a.size();i++) s = char(a[i]+'0') + s;
    return s;
}

int main()
{
    string s;
    int k=10;
    vector<int> t;
    cin>>s;
    int cnt=1;
    
    for (int i = s.size() - 1; i >= 0; i -- ) t.push_back(s[i] - '0');
    

    if(!check(t))
    {

        while(cnt<=k)
        {
            vector<int> r(t.rbegin(),t.rend());
            cout<<getnum(t)<<" + "<<getnum(r)<<" = ";
            t = add(t,r);
            cout<<getnum(t)<<endl;
            if (check(t)) break;
            cnt++;
        }
        
    }
    
    if(cnt>k) cout<<"Not found in 10 iterations.";
    else cout<<getnum(t)<<" is a palindromic number.";
    return 0;
}
