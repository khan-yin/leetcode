// PAT甲级真题1098
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;

int n;
int a[N],b[N];


void down(int x, int size)
{
    int t = x;
    if(2*x<=size && b[2*x]>b[t]) t = 2*x;
    if(2*x+1<=size && b[2*x+1]>b[t]) t = 2*x+1;
    if(t!=x)
    {
        swap(b[x],b[t]);
        down(t,size);
    }
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
    }
    else
    {
        puts("Heap Sort");
        int p = n;
        while(p>1&&b[1]<=b[p]) p--;
        swap(b[1],b[p]);
        down(1,p-1);
    }
    cout<<b[1];
    for(int i=2;i<=n;i++) cout<<" "<<b[i]; 
    
    
    return 0;
}