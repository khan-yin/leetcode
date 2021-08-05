// PAT甲级真题1112
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

const int N = 200;

int vis[N];


int main()
{
    int k;
    scanf("%d", &k);
    string a;
    cin>>a;

    for(int i=0;i<a.size();i++)
    {
        int j=i+1;
        while(j<a.size() && a[i]==a[j]) j++;
        int len = j-i;
        if(len%k) vis[a[i]]=1;
        i=j-1;
    }
    string res;
    for(int i=0;i<a.size();i++)
    {
        if(!vis[a[i]]) cout<<a[i], vis[a[i]]=2;
        if(vis[a[i]]==1)
        {
            res += a[i];
        }
        else
        {
            res +=a[i];
            i += k -1;
        }
    }
    cout<<endl<<res<<endl;
    return 0;
}
