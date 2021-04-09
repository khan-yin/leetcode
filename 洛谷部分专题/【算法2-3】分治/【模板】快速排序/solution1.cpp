#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[100006];

void quick_sort(int l,int r)
{
    if(l>r)
        return;
    int i=l;
    int j=r;
    int key=a[i];
    while(i<j)
    {
        while(i<j&&a[j]>=key) j--;
        swap(a[i],a[j]);
        while(i<j&&a[i]<=key) i++;
        swap(a[j],a[i]);
    }
    quick_sort(l,j-1);
    quick_sort(i+1,r);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    quick_sort(1,n);
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}