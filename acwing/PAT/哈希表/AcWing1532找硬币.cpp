// PAT甲级真题1048
#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

const int N = 100010;
int n,m;
int a[N];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &a[i]);
    sort(a,a+n);
    unordered_map<int,int> hash;
    
    for(int i=0;i<n;i++)
    {
        hash[a[i]]++;
    }
    
    for(int i=0;i<n;i++)
    {
        int num = m - a[i];
        if(num<a[i]) break;
        else if(num==a[i]&&hash[num]<2) break;
        if(hash.count(num))
        {
            cout<<a[i]<<' '<<num;
            return 0;
        }
    }
    
    cout<<"No Solution";
    
    return 0;
}