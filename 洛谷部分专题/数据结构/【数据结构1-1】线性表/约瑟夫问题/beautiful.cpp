#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;

    vector<int> a;
    for(int i=0;i<n;i++)
    {
        a.push_back(i+1);
    }

    int at=0;
    while(a.size()>0)
    {
        at=(at+m-1)%a.size();
        cout<<a[at]<<" ";
        a.erase(a.begin()+at);
    }
    return 0;
}