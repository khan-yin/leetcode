#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N],b[N];


bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i]) return false;
    }
    return true;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]; 
    for(int i=1;i<=n;i++) cin>>b[i]; 
    
    int p = 2;
    while(p<=n&&b[p-1]<=b[p]) p++;
    
    int k = p;
    while(p<=n&&a[p]==b[p]) p++;
    if(p==n+1)
    {
        puts("Insertion Sort");
        while(k>1&&b[k]<b[k-1]) swap(b[k],b[k-1]), k--;
        cout<<b[1];
        for(int i=2;i<=n;i++) cout<<" "<<b[i];
    }
    else
    {
        puts("Merge Sort");
        int k =1;
        while(true)
        {
            bool flag = check();
            int len = 1<<k;
            for(int i=1;i<=n;i+=len)
            {
                sort(a+i,a+min(n+1,i+len));
            }
            if(flag) break;
            k++;
        }
        cout<<a[1];
        for(int i=2;i<=n;i++) cout<<" "<<a[i];
        
    }
    
    
    
    
    return 0;
}