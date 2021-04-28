#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int a[N];

void quick_sort(int q[],int l,int r)
{
    if(l>=r)
        return;
    
    int x=q[l + r >> 1];
    int i=l-1,j=r+1;
    while(i<j)
    {
        do i++; while(a[i]<x);
        do j--; while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    
    quick_sort(q,l,j);
    quick_sort(q,j+1,r);
}


int main()
{
    int n,k;
    scanf("%d%d", &n, &k);
    
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        
    quick_sort(a,1,n);
    cout<<a[k];
    
    return 0;
}