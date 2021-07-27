// PAT甲级真题1023
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 30;


int main()
{
    string n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n.size();i++) a.push_back(n[i] - '0');
    
    vector<int> b;
    int t=0; //进位
    for(int i=a.size()-1;i>=0;i--)
    {
        
        b.push_back((a[i]+a[i]+t)%10);
        t = (a[i]+a[i]+t) / 10;
    }
    
    if(t) b.push_back(t);

    vector<int> c=b;
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    if(a==c) puts("Yes");
    else puts("No");
    
    for(int i = b.size() -1;i>=0;i--) cout<<b[i];
    
    return 0;
}